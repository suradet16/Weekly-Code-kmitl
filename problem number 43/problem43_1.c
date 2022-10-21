#include<stdio.h>

int isPandigital(long long int);
int isSatisfying(long long int);

int main()
{
      int a,b,c,d,e,f,g,h,i,j;
      long long int num,sum=0;
      for(a=1;a<10;a++)
       for(num=a,b=0;b<10;b++)
        if(isPandigital(num=a*10+b))
         for(c=0;c<10;c++)
          if(isPandigital(num=a*100+b*10+c))
           for(d=0;d<10;d++)
            if(isPandigital(num=a*1000+b*100+c*10+d))
             for(e=0;e<10;e++)
              if(isPandigital(num=a*10000+b*1000+c*100+10*d+e))
               for(f=0;f<10;f++)
                if(isPandigital(num=a*100000+10000*b+1000*c+100*d+10*e+f))
               for( g=0;g<10;g++)
                if(isPandigital(num=a*1000000+b*100000+c*10000+d*1000+e*100+f*10+g))
                 for(h=0;h<10;h++)
                  if(isPandigital(num=a*10000000+b*1000000+c*100000+d*10000+e*1000+f*100+g*10+h))
                   for(i=0;i<10;i++)
                  if(isPandigital(num=a*100000000ll+b*10000000ll+c*1000000ll+d*100000ll+e*10000ll+f*1000ll+g*100ll+h*10ll+i))
                   for(j=0;j<10;j++)
                    if(isPandigital(num=a*1000000000ll+b*100000000ll+c*10000000ll+d*1000000ll+e*100000ll+f*10000ll+g*1000ll+h*100ll+i*10ll+j))
                     if(isSatisfying(num))
                     {
                        printf("%lld\n",num);
                        sum+=num;
                     }
      printf("sum = %lld\n",sum);
      return 0;
}

int isSatisfying(long long int n)
{
      if((n%1000000000/1000000)%2!=0)
            return 0;
      if((n%100000000/100000)%3!=0)
            return 0;
      if((n%10000000/10000)%5!=0)
            return 0;
      if((n%1000000/1000)%7!=0)
            return 0;
      if((n%100000/100)%11!=0)
            return 0;
      if((n%10000/10)%13!=0)
            return 0;
      if((n%1000)%17!=0)
            return 0;
      return 1;
}

int isPandigital(long long int n)
{
      int arr[10]={0},i;
      while(n)
      {
            arr[n%10]++;
            n/=10;
      }
      for(i=0;i<10;i++)
            if(arr[i]>=2)
                  return 0;
      return 1;
}