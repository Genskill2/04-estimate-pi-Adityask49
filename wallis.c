#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float wallis_pi(int);

int main(void) {
  float pi0;
  float pi1;
  
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
{
  float ret=1.0;
  float base;
  for(int i=0;i<=n;i++)
  { base=(float)(4*i*i)/((4*i*i)-1);
   ret=ret*base;
  }
  ret=ret*2;
  return ret;
}

