#include<cmath>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include <iostream>
using namespace std;
typedef long long i64;
#define MAX 100105
#define power(x)((x)*(x))
struct point{ double x, y; };
struct cmpX{
	bool operator() (const point &a, const point &b){
		return a.x < b.x;
	}
};
struct cmpY{
	bool operator() (const point &a, const point &b){
		return a.y < b.y;
	}
};
double Euclidean_Dist(point a,point b){
	return sqrt(power(a.x-b.x)+power(a.y-b.y));
}
int ManhattanDist(point a,point b){
	return abs(abs(a.x-b.x)+abs(a.y-b.y));
}
struct KDtree{
	point boundary;
	KDtree *left;
	KDtree *right;
	int d; // dimension 0: left/right split 1: up/down split
	int cantNodes;
	point UpLeft; //estos puntos
	point UpRight; //me delimitan
	point DownLeft; //el rectangulo
	point DownRight; //que cubre ese borde
};
int N,Q;
point P[MAX];
KDtree *root;
double xmin,xmax,ymin,ymax;
KDtree *build(int a, int b, int depth){
	if(a <= b){
		KDtree *node = new KDtree();
		node->d = depth % 2;
		if(node->d==0) sort(P+a,P+a+(b-a+1),cmpX());
		else sort(P+a,P+a+(b-a+1),cmpY());
		int med = a + (b-a+1)/2;
		node->boundary = P[med];
		node->left = build(a,med-1,depth+1);
		node->right = build(med+1,b,depth+1);
		node->cantNodes = (b-a+1);
		return node;
	}
	return NULL;
}

bool isInside(point target, double radio, KDtree *node ){
	int ok=0;
	if(Euclidean_Dist(target,node->DownLeft)<=radio) ok++;
	if(Euclidean_Dist(target,node->DownRight)<=radio) ok++;
	if(Euclidean_Dist(target,node->UpLeft)<=radio) ok++;
	if(Euclidean_Dist(target,node->UpRight)<=radio) ok++;
	return ok==4;
}
int findPoints(point target, double radio, KDtree *node){
	int cant = 0;
	if(isInside(target,radio,node))return node->cantNodes;;
	if( Euclidean_Dist(target,node->boundary) <= radio ) cant++;
	double spacing = target.x - node->boundary.x;
	if(node->d==1) spacing = target.y - node->boundary.y;
	KDtree *rightSide = (spacing < 0) ? node->left : node->right;
	KDtree *otherSide = (spacing < 0) ? node->right : node->left;
	if(rightSide != NULL)
		cant += findPoints(target,radio,rightSide);
	if(otherSide != NULL && abs(spacing) <= radio)
		cant += findPoints(target,radio,otherSide);
	return cant;
}
void recorre(KDtree *node){
	if(node->left!=NULL){
		if(node->d == 0){
			node->left->DownLeft = node->DownLeft;

			node->left->DownRight.x = node->boundary.x;
			node->left->DownRight.y = node->DownRight.y;

			node->left->UpLeft = node->UpLeft;

			node->left->UpRight.x = node->boundary.x;
			node->left->UpRight.y = node->UpRight.y;
		}else{
			node->left->DownLeft = node->DownLeft;

			node->left->DownRight = node->DownRight;

			node->left->UpLeft.x = node->UpLeft.x;
			node->left->UpLeft.y = node->boundary.y;

			node->left->UpRight.x = node->UpRight.x;
			node->left->UpRight.y = node->boundary.y;
		}
		recorre(node->left);
	}

	if(node->right != NULL){
		if(node->d == 0){
			node->right->DownLeft.x = node->boundary.x;
			node->right->DownLeft.y = node->DownLeft.y;

			node->right->DownRight = node->DownRight;

			node->right->UpLeft.x = node->boundary.x;
			node->right->UpLeft.y = node->UpRight.y;

			node->right->UpRight = node->UpRight;
		}else{
			node->right->DownLeft.x = node->DownLeft.x;
			node->right->DownLeft.y = node->boundary.y;

			node->right->DownRight.x = node->DownRight.x;
			node->right->DownRight.y = node->boundary.y;

			node->right->UpLeft = node->UpLeft;

			node->right->UpRight = node->UpRight;
		}
		recorre(node->right);
	}
}
point findClosest(point target, KDtree *node){
	point closest;
	if(target.x==node->boundary.x && target.y==node->boundary.y){
		closest.x = 1e9, closest.y = 1e9;
		return target;
	}
	else
		closest = node->boundary;
	double  bestDist = Euclidean_Dist(closest, target);
	double spacing = target.x - node->boundary.x;
	if(node->d==1) spacing = target.y - node->boundary.y;
	KDtree *rightSide = (spacing < 0) ? node->left : node->right;
	KDtree *otherSide = (spacing < 0) ? node->right : node->left;
	if(rightSide != NULL){
		point candidate = findClosest(target,rightSide);
		if(Euclidean_Dist(candidate,target) < bestDist){
			closest = candidate;
			bestDist = Euclidean_Dist(closest,target);
		}
	}
	if(otherSide != NULL && abs(spacing) < bestDist){
		point candidate = findClosest(target, otherSide);
		if(Euclidean_Dist(candidate,target) < bestDist){
			closest = candidate;
			bestDist = Euclidean_Dist(target, closest);
		}
	}
	return closest;
}
int main(){
	xmin=xmax=ymin=ymax=-1;
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;i++){
		scanf("%lf%lf",&P[i].x, &P[i].y);
		if(xmin==-1 || xmin>P[i].x) xmin=P[i].x;
		if(xmax==-1 || xmax<P[i].x) xmax=P[i].x;
		if(ymin==-1 || ymin>P[i].y) ymin=P[i].y;
		if(ymax==-1 || ymax<P[i].y) ymax=P[i].y;
	}
	root = build(0,N-1,0);
	root->DownLeft.x = xmin;
	root->DownLeft.y = ymin;
	root->DownRight.x = xmax;
	root->DownRight.y = ymin;
	root->UpLeft.x = xmin;
	root->UpLeft.y = ymax;
	root->UpRight.x = xmax;
	root->UpRight.y = ymax;
	recorre(root);
	double x,y;
	for(int i = 0; i <Q; ++i){
		scanf("%lf%lf",&x,&y);
		point target = point{x,y};
		double ans=Euclidean_Dist(findClosest(target,root),target);
		printf("%.2lf\n",ans+1e-9);
	}
	return 0;
}


