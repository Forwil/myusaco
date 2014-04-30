
/*  
 ID: forwil11
 LANG: C++
 TASK: packrec
*/

#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

struct rectangles
{
    int x,y;
} r[4],tr[4];

struct ANS
{
    int x,y,area,bug;
} ans[3000];
int k;

void fun1(rectangles *A)
{
    int i,a,b;
    a=b=0;
    for(i=0; i<4; i++)
    {
        a+=A[i].x;
        if(b<A[i].y)
            b=A[i].y;
    }
    if(a>b) swap(a,b);
    ans[k].x=a;
    ans[k].y=b;
    ans[k].area=a*b;
    ans[k].bug=1;
    k++;
}

void fun2(rectangles *A)
{
    int a,b;
    a=max(A[0].y,A[1].x+A[2].x+A[3].x);
    b=A[0].x+max(A[1].y,max(A[2].y,A[3].y));
    if(a>b) swap(a,b);
    ans[k].x=a;
    ans[k].y=b;
    ans[k].area=a*b;
    ans[k].bug=2;
    k++;
}

void fun3(rectangles *A)
{
    int a,b;
    a=A[1].x+max(A[0].y,A[2].x+A[3].x);
    b=A[0].x+max(A[2].y,A[3].y);
    b=max(b,A[1].y);
    if(a>b) swap(a,b);
    ans[k].x=a;
    ans[k].y=b;
    ans[k].area=a*b;
    ans[k].bug=3;
    k++;
}

void fun4(rectangles *A)
{
    int a,b;
    a=A[0].x+A[1].x;
    a=a+max(A[2].x,A[3].x);
    b=A[2].y+A[3].y;
    b=max(b,max(A[0].y,A[1].y));
    if(a>b) swap(a,b);
    ans[k].x=a;
    ans[k].y=b;
    ans[k].area=a*b;
    ans[k].bug=4;
    k++;
}

void fun5(rectangles *A)
{
    int a,b;
    a=max(A[0].y+A[3].y,A[1].y+A[2].y);
    if(A[0].y>=A[1].y&&A[2].x>A[1].x)
    {
        a=max(a,A[0].y+A[2].y);
    }
    if(A[0].y<=A[1].y&&A[3].x>A[0].x)
    {
        a=max(a,A[1].y+A[3].y);
    }
    b=max(A[0].x+A[1].x,A[2].x+A[3].x);
    if(a>b) swap(a,b);
    ans[k].x=a;
    ans[k].y=b;
    ans[k].area=a*b;
    ans[k].bug=5;
    k++;
}

bool cmp(ANS A,ANS B)
{
    if(A.area<B.area) return true;
    if(A.area==B.area&&A.x<B.x) return true;
    if(A.area==B.area&&A.x==B.x&&A.y<B.y) return true;
    return false;
}

int main()
{
    freopen("packrec.in","r",stdin);
    freopen("packrec.out","w",stdout);
    int i,a,b,c,d;
    while(~scanf("%d%d%d%d%d%d%d%d",&r[0].x,&r[0].y,&r[1].x,&r[1].y,&r[2].x,&r[2].y,&r[3].x,&r[3].y))
    {
        int p[4];
        for(i=0; i<4; i++)
            p[i]=i;
        do
        {
            for(i=0; i<4; i++)
            {
                tr[i].x=r[p[i]].x;
                tr[i].y=r[p[i]].y;
            }
            for(a=0;a<2;a++)
            {
                swap(tr[0].x,tr[0].y);
                for(b=0;b<2;b++)
                {
                    swap(tr[1].x,tr[1].y);
                    for(c=0;c<2;c++)
                    {
                        swap(tr[2].x,tr[2].y);
                        for(d=0;d<2;d++)
                        {
                            swap(tr[3].x,tr[3].y);
                            fun1(tr);fun2(tr);fun3(tr);
                            fun4(tr);
                            fun5(tr);
                        }
                    }
                }
            }
        }while(next_permutation(p,p+4));
        sort(ans,ans+k,cmp);
        int min_area=ans[0].area;
        printf("%d\n",min_area);
        printf("%d %d\n",ans[0].x,ans[0].y);
        for(i=1;i<k;i++)
        {
            if(ans[i].area==min_area)
            {
                if(ans[i].x==ans[i-1].x) continue;
                printf("%d %d\n",ans[i].x,ans[i].y);
            }
            else
                break;
        }
    }
    return 0;
}
