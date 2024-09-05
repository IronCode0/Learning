# %%
from sklearn import svm
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

# %%
iris = datasets.load_iris()
# iris.data
# iris.feature_names
# iris.target
x = iris.data[:,2]
y = iris.target

# %%
x_train,x_test,y_train,y_test = train_test_split(x,y,test_size=0.2, random_state=5)
x_train_mod = x_train.reshape(-1,1)
x_test_mod  = x_test.reshape(-1,1)
y_train_mod = y_train.reshape(-1,1)
y_test_mod  = y_test.reshape(-1,1)
model = svm.SVC(kernel='linear')
model.fit(x_train_mod,y_train_mod)
y_pred_mod = model.predict(x_test_mod)
accuracy = accuracy_score(y_test_mod,y_pred_mod)
print(accuracy)




