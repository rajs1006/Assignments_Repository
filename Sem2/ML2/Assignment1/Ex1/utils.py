import numpy as np
import scipy,scipy.spatial

# ----------------------------------------
# Compute the pairwise affinities
# ----------------------------------------

def getaffinity(X,target):

	N,d = X.shape

	D2 = scipy.spatial.distance.cdist(X,X,'sqeuclidean')

	# Initial scales
	sqsigma = 0.1*np.ones([len(X)])*D2.mean()

	for k in range(1,101):

		# Stable computation of probability vector
		ulogp = - D2 / (2*sqsigma[:,np.newaxis])
		logp  = ulogp - scipy.misc.logsumexp(ulogp,axis=1)[:,np.newaxis]

		# Computation of perplexity
		perp = 2.0**(-(np.exp(logp)*logp/np.log(2)).sum(axis=1))

		if k % 25 == 0: print('%3d %.3f %.3f'%(k,perp.mean(),target))

		sqsigma *= 1.0+5.0/(k+5.0)*np.sign(target-perp)

	# Symmetrize the affinity matrix
	logp = scipy.misc.logsumexp([logp,logp.T],axis=0) - np.log(2*N)
		
	return logp

# ----------------------------------------
# Read a dataset
# ----------------------------------------

def get_data(mode=1):

	if(mode==1):
		print "Loading digits"
		from sklearn.datasets import load_digits
		D=load_digits()

	if(mode==2):
		print "Loading boston housing"
		from sklearn.datasets import load_boston
		D=load_boston()

	if(mode==3):
		print "Loading iris"
		from sklearn.datasets import load_iris
		D=load_iris()
	  
	# Read only 500 first examples
	X = D.data[:500]
	T = D.target[:500]

	# Normalize them
	X -= X.mean(axis=0)
	X /= (X**2).sum(axis=1).mean()**.5

	return 5*X,T

