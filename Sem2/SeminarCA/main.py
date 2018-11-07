import os
import numpy as np
import matplotlib as mpl


####################################################################################################
# Exercise 1: Power Iteration

def power_iteration(M: np.ndarray, epsilon: float = -1.0) -> (np.ndarray, list):
    """
    Compute largest eigenvector of matrix M using power iteration. It is assumed that the
    largest eigenvalue of M, in magnitude, is well separated.

    Arguments:
    M: matrix, assumed to have a well separated largest eigenvalue
    epsilon: epsilon used for convergence (default: 10 * machine precision)

    Return:
    vector: eigenvector associated with largest eigenvalue
    residuals : residual for each iteration step

    Raised Exceptions:
    ValueError: if matrix is not square

    Forbidden:
    numpy.linalg.eig, numpy.linalg.eigh, numpy.linalg.svd
    """
    if M.shape[0] != M.shape[1]:
        raise ValueError("Matrix not nxn")
    if epsilon == -1.0:
        epsilon = 10 * np.finfo(np.dtype("float")).eps
        print(epsilon)

    vector = np.random.randn(M.shape[0])
    # Initialize residual list and residual of current eigenvector estimate
    residuals = []
    residual = 2.0 * epsilon

    # Perform power iteration
    while residual > epsilon:
        vector_temp = vector
        z = np.dot(M, vector)
        vector = z / np.linalg.norm(z)
        residual = np.linalg.norm((vector - vector_temp))
        residuals.append(residual)
        # print(residual)

    return vector, residuals


####################################################################################################
# Exercise 2: Eigenfaces

def load_images(path: str, file_ending: str=".png") -> (list, int, int):
    """
    Load all images in path with matplotlib that have given file_ending

    Arguments:
    path: path of directory containing image files that can be assumed to have all the same dimensions
    file_ending: string that image files have to end with, if not->ignore file

    Return:
    images: list of images (each image as numpy.ndarray and dtype=float64)
    dimension_x: size of images in x direction
    dimension_y: size of images in y direction
    """

    images = []
    for file in sorted(os.listdir(path)):
        if file.endswith(file_ending):
            image = np.asarray(mpl.image.imread(path + file, format="png"), dtype=np.float64)
            images.append(image)     
    # Useful functions: matplotlib.image.imread(), numpy.asarray()

    image = images[0]
    dimension_y = image.shape[0]
    dimension_x = image.shape[1]
    
    return images, dimension_x, dimension_y


def setup_data_matrix(images: list) -> np.ndarray:
    """
    Create data matrix out of list of 2D data sets.

    Arguments:
    images: list of 2D images (assumed to be all homogeneous of the same size and type np.ndarray)

    Return:
    D: data matrix that contains the flattened images as rows
    """
    
    D = np.zeros((len(images), images[0].shape[1] * images[0].shape[0]), dtype=np.float64)
    i = 0
    for i in range(len(images)):
        D[i] = images[i].flatten()

    return D


def calculate_pca(D: np.ndarray) -> (np.ndarray, np.ndarray, np.ndarray):
    """
    Perform principal component analysis for given data matrix.

    Arguments:
    D: data matrix of size m x n where m is the number of observations and n the number of variables

    Return:
    pcs: matrix containing principal components as rows
    svals: singular values associated with principle components
    mean_data: mean that was subtracted from data
    """

    mean_data = D.mean(0)
    
    D = D - mean_data
    # Useful functions: numpy.linalg.svd(..., full_matrices=False)
    u, svals, pcs = np.linalg.svd(D, full_matrices=False)
    
    return pcs, svals, mean_data


def accumulated_energy(singular_values: np.ndarray, threshold: float = 0.8) -> int:
    """
    Compute index k so that threshold percent of magnitude of singular values is contained in
    first k singular vectors.

    Arguments:
    singular_values: vector containing singular values
    threshold: threshold for determining k (default = 0.8)

    Return:
    k: threshold index
    """
    normalized = np.std(singular_values)
    i = 0
    for i in range(singular_values.shape[0]):
        singular_values[i] = singular_values[i] / normalized      
        
    acc_energy = 0
    k = 0
    while acc_energy <= threshold * np.sum(singular_values):
        acc_energy = acc_energy + singular_values[k]
        k = k + 1
    return k


def project_faces(pcs: np.ndarray, images: list, mean_data: np.ndarray) -> np.ndarray:
    """
    Project given image set into basis.

    Arguments:
    pcs: matrix containing principal components / eigenfunctions as rows
    images: original input images from which pcs were created
    mean_data: mean data that was subtracted before computation of SVD/PCA

    Return:
    coefficients: basis function coefficients for input images, each row contains coefficients of one image
    """

    coefficients = np.zeros((len(images), pcs.shape[0]))

    i = 0

    for i in range(coefficients.shape[0]):
        coefficients[i] = np.dot(pcs, images[i].flatten() - mean_data)
    
    return coefficients


def identify_faces(coeffs_train: np.ndarray, pcs: np.ndarray, mean_data: np.ndarray, path_test: str) -> (
np.ndarray, list, np.ndarray):
    """
    Perform face recognition for test images assumed to contain faces.

    For each image coefficients in the test data set the closest match in the training data set is calculated.
    The distance between images is given by the angle between their coefficient vectors.

    Arguments:
    coeffs_train: coefficients for training images, each image is represented in a row
    path_test: path to test image data

    Return:
    scores: Matrix with correlation between all train and test images, train images in rows, test images in columns
    imgs_test: list of test images
    coeffs_test: Eigenface coefficient of test images
    """

    imgs_test, dim_x, dim_y = load_images(path_test)
    
    coeffs_test = project_faces(pcs, imgs_test, mean_data)

    scores = np.zeros((coeffs_train.shape[0], coeffs_test.shape[0]))
    
    for i in range(coeffs_train.shape[0]):       
        for j in range(coeffs_test.shape[0]):
            scores[i][j] = np.arccos(np.dot(coeffs_train[i, :] / np.linalg.norm(coeffs_train[i, :]), coeffs_test[j, :] / np.linalg.norm(coeffs_test[j, :])))
                
    #print(scores)
    #print("Coeffs_test.shape: " + str(coeffs_test.shape))
    #print("Coeffs_train.shape: " + str(coeffs_train.shape))
    #print("Scores.shape: " + str(scores.shape))
    return scores, imgs_test, coeffs_test

if __name__ == '__main__':
    print("All requested functions for the assignment have to be implemented in this file and uploaded to the "
          "server for the grading.\nTo test your implemented functions you can "
          "implement/run tests in the file tests.py (> python3 -v test.py [Tests.<test_function>]).")
