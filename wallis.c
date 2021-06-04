#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float wallis_pi(int);

float mc_pi(int);
float frandom(){
  long int q=random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

int main(void) {
  float pi;
  float pi0;
  
  pi0=mc_pi(25000);
  pi1=mc_pi(25000);
  printf("%f %f\n", pi0,pi1);
  
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}
float mc_pi(int n)
{ float t,x,y;
 int within_circle=0;
 int outside_circle=0;
 int total_point=0;
 for(int i=0;i<=n;i++)
 { x=frrandom();
  y=frandom();
  t=(x*x)+(y*y);
  if(t<=1)
  { within_circle++;
  }
  else
  { outside_circle++;
  }
 }
 total_points= within_circle+ outside_circle;
 float pi= 4*(float)within_circle/total_points;
 return pi;
}

