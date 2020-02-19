#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int count_zero(int l,int r,char*s)
{
  int i;
  int count=0;
  for(i=l;i<=r;i++)
  {
    if(s[i]=='0')
    {
      count++;
    }
  }
  return count;
}
int count_one(int l,int r,char*s)
{
  int i;
  int count=0;
  for(i=l;i<=r;i++)
  {
    if(s[i]=='1')
    {
      count++;
    }
  }
  return count;
}
int findk(int l,int r,char*s)
{
  int k,mid=(l+r)/2;
  if(count_one(l,mid,s)==count_zero(mid+1,r,s))
  return mid;
  else if(count_one(l,mid,s)>count_zero(mid+1,r,s))
  {
    findk(l,mid,s);
  }
  else if(count_one(l,mid,s)<count_zero(mid+1,r,s))
  {
    findk(mid+1,r,s);
  }
  return -1;
}
int main()
{
  int v;
  char s[20];
  scanf("%s",s);
  int l=strlen(s);
  v=findk(0,l-1,s);
  printf("%d\n",v);

}
