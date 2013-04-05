#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
#include<climits>
using namespace std;

/*Declarations*/
int t,q,n,tid[10001],qtopic[1001][12],qid[1001],qnum[1001],result,rev_index[100005];
double topic[10001][2],qrx,qry,tmp,min1,tmp1;
char qrtype;
vector<int> v;
vector<double> w;
priority_queue<pair<double,int> > pq;

inline double f_abs(double r)
{
if(r<0)
return -r;
return r;
}

inline int f_min(int a,int b)
{
if(a<=b)
return a;
return b;
}

inline double f_eucd(double x1,double y1,double x2,double y2)
{
return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

void f_process_topic(vector<int> &v)
{
if(result==0 || t==0)
return;
for(int j=0;j<f_min(t,result);j++)
pq.push(make_pair(f_eucd(qrx,qry,topic[j][0],topic[j][1]),-1*tid[j]));
for(int j=result;j<t;j++)
{
tmp=f_eucd(qrx,qry,topic[j][0],topic[j][1]);
if(tmp<(pq.top()).first || (tmp==(pq.top()).first && tid[j]>-1*((pq.top()).second)))
{pq.pop();pq.push(make_pair(tmp,-1*tid[j]));}
}
while(!pq.empty())
{
v.push_back(-1*((pq.top()).second));
pq.pop();
}
}

void f_process_question(vector<int> &v)
{
if(result==0 || q==0)
return;
w.clear();
for(int i=0;i<q;i++)
{
min1=INT_MAX;
for(int j=0;j<qnum[i];j++)
{
tmp1=f_eucd(qrx,qry,topic[rev_index[qtopic[i][j]]][0],topic[rev_index[qtopic[i][j]]][1]);
if(tmp1<min1)
min1=tmp1;
}
w.push_back(min1);
}
for(int j=0;j<f_min(q,result);j++)
pq.push(make_pair(w[j],-1*qid[j]));
for(int j=result;j<q;j++)
{
if(w[j]<(pq.top()).first || (w[j]==(pq.top()).first && qid[j]>-1*((pq.top()).second)))
{pq.pop();pq.push(make_pair(w[j],-1*qid[j]));}
}
while(!pq.empty())
{
if((pq.top()).first<INT_MAX)
v.push_back(-1*((pq.top()).second));
pq.pop();
}
}

void f1(vector<int> &v)
{
if(result==0 || t==0)
return;
vector<pair<double,int> > h;
for(int i=0;i<t;i++)
h.push_back(make_pair(f_eucd(qrx,qry,topic[i][0],topic[i][1]),-1*tid[i]));
/*sort(h.begin(),h.end());
for(int i=f_min(t,result)-1;i>=0;i--)
v.push_back(-1*(h[i].second));*/
for(int i=0;i<f_min(t,result);i++)
pq.push(make_pair(h[i].first,h[i].second));
for(int i=f_min(t,result);i<t;i++)
{
if(h[i].first<(pq.top()).first || (h[i].first==(pq.top()).first && tid[i]>-1*(pq.top()).second))
{pq.pop();pq.push(make_pair(h[i].first,h[i].second));}
}
while(!pq.empty())
{
v.push_back(-1*((pq.top()).second));
pq.pop();
}
}

void f2(vector<int> &v)
{
if(result==0 || q==0)
return;
vector<pair<double,int> > h;
w.clear();
double min1,tmp1;
for(int i=0;i<q;i++)
{
min1=INT_MAX;
for(int j=0;j<qnum[i];j++)
{
tmp1=f_eucd(qrx,qry,topic[rev_index[qtopic[i][j]]][0],topic[rev_index[qtopic[i][j]]][1]);
if(tmp1<min1)
min1=tmp1;
}
w.push_back(min1);
}
for(int i=0;i<q;i++)
h.push_back(make_pair(w[i],-1*qid[i]));
/*sort(h.begin(),h.end());
for(int i=f_min(q,result)-1;i>=0;i--)
{
if(h[i].first<INT_MAX)
v.push_back(-1*(h[i].second));
}*/
for(int i=0;i<f_min(q,result);i++)
pq.push(make_pair(h[i].first,h[i].second));
for(int i=f_min(q,result);i<q;i++)
{
if(h[i].first<(pq.top()).first || (h[i].first==(pq.top()).first && qid[i]>-1*(pq.top()).second))
{pq.pop();pq.push(make_pair(h[i].first,h[i].second));}
}
while(!pq.empty())
{
if((pq.top()).first<INT_MAX)
v.push_back(-1*((pq.top()).second));
pq.pop();
}
}


int main()
{

/*Input*/
cin>>t>>q>>n;
for(int i=0;i<t;i++)
{
cin>>tid[i]>>topic[i][0]>>topic[i][1];
rev_index[tid[i]]=i;
}
for(int i=0;i<q;i++)
{
cin>>qid[i]>>qnum[i];
for(int j=0;j<qnum[i];j++)
cin>>qtopic[i][j];
}

/*Processing*/
for(int i=0;i<n;i++)
{
while(!pq.empty())
pq.pop();
v.clear();
//getchar();
cin>>qrtype>>result>>qrx>>qry;
if(qrtype=='t')
/*f1(v);*/f_process_topic(v);
else
/*f2(v);*/f_process_question(v);
for(int j=v.size()-1;j>=0;j--)
cout<<v[j]<<" ";
cout<<endl;
}

return 0;
}
