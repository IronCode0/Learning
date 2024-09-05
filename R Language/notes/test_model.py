import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from mlxtend.feature_selection import SequentialFeatureSelector as sf
from sklearn.metrics import accuracy_score as acc
from joblib import load


df=pd.read_csv("F:\\NIT\\Programming\\CEC\\notes\\winequality-white.csv", sep=';')
x_train,x_test,y_train,y_test = train_test_split(df.values[:,:-1],df.values[:,-1:],test_size=0.20,random_state=1)


x_train = load('F:\\NIT\\Programming\\CEC\\notes\\x_train.joblib')
y_train = load('F:\\NIT\\Programming\\CEC\\notes\\y_train.joblib')

cl=RandomForestClassifier(n_estimators=100, n_jobs=-1)
#ofs1=sf(cl,forward=True,floating=False,verbose=2,scoring=1)
#ofs1=sf(cl,k_features='best',forward=True,floating=False,verbose=2)

#ofs=ofs1.fit(x_train,y_train)
#fsel=list(ofs.k_feature_idx_)

y_pred=cl.predict(x_train)
print("accuracy=",acc(y_train,y_pred))

