import numpy
import sys
from sklearn.linear_model import LogisticRegression
p = (raw_input()).split()
m = long(p[0])
n = long(p[1])
q_data = numpy.zeros(shape=(m,n))
q_result = numpy.zeros(shape=(m))
q = None
r = None
for i in range(0,m):
    q = (raw_input()).split()
    q_result[i] = long(q[1])
    for j in range(2,n+2):
        r = q[j].split(':')
        q_data[i][j-2] = float(r[1])
#print q_data
#print q_result
trained_model = LogisticRegression().fit(q_data, q_result)
query = long(raw_input())
X = numpy.zeros(shape=(query,n))
name_id = []
for i in range(0,query):
    q = (raw_input()).split()
    name_id.append(q[0])
    for j in range(1,n+1):
        r = q[j].split(':')
        X[i][j-1] = float(r[1]) 
predictions = trained_model.predict(X)
#print X
#print name_id
#print predictions
for i in range(0,query):
    if(predictions[i]==-1):
        print "%s %d" %(name_id[i],predictions[i])
    else:
        print "%s +%d" %(name_id[i],predictions[i])
    sys.stdout.flush()
