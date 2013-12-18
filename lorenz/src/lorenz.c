#include <stdlib.h>
#include <stdio.h>

//define parameters and initial conditions
#define A 10
#define B 8/3
#define N 10000
#define R 28
#define M 0
#define DT 0.01
#define X 1
#define Y 1
#define Z 1
#define SCNF 0

//*Start of main function*//
                   
int main()
{
//initialise variables and assign values
    int i;                  //counter
    int n=N;                //number of iterations
    int m=M;                //which graph to print out
    double t;               //time coord
    double a=A;             //parameter a
    double b=B;             //parameter b
    double dt=DT;           //time increment
    double r=R;             //parameter r determining ex0tent of chaos
    double x0=X;             //initial x0 coord
    double y0=Y;             //initial y0 coord
    double z0=Z;             //initial z0 coord
    printf("Parameters and intial variables\na:  %lf\nb:  %lf\nn:  %d\nr:  %lf\ndt: %lf\nx0:  %lf\ny0:  %lf\nz0:  %lf\n\n",a,b,n,r,dt,x0,y0,z0);

    //scanf condition
    if(SCNF == true){
      printf("Define the no. of steps n, the starting points (x0, y0, z0) and the value of r all separated by0 spaces.\n");
      scanf("%d %lf %lf %lf %lf", &n, &x0, &y0, &z0, &r);
    }
    
    //defining output file pointer
    FILE *fchaos;
    if ((fchaos = fopen("output.data", "w")) == NULL) {
      printf("Cannot open %s\n", "output.data");
      exit(EXIT_FAILURE);
    }

//start of main process
    double fx0, fx1, fx2, fx3, fx4, fy0, fy1, fy2, fy3, fy4, fz0, fz1, fz2, fz3, fz4, x, y, z;
    t = 0;
    for(i = 0; i<n; i++){

      fx0 = a*(y0-x0);
      fy0 = r*x0-y0-x0*z0;
      fz0 = x0*y0-b*z0;
      x = x0+fx0*dt/2;
      y = y0+fy0*dt/2;
      z = z0+fz0*dt/2;

      fx1 = a*(y-x);
      fy1 = r*x-y-x*z;
      fz1 = x*y-b*z;
      x = x0+fx1*dt/2;
      y = y0+fy1*dt/2;
      z = z0+fz1*dt/2;

      fx2 = a*(y-x);
      fy2 = r*x-y-x*z;
      fz2 = x*y-b*z;
      x = x0+fx2*dt;
      y = y0+fy2*dt;
      z = z0+fz2*dt;

      fx3 = a*(y-x);
      fy3 = r*x-y-x*z;
      fz3 = x*y-b*z;
      x = x0+(fx0+2*fx1+2*fx2+fx3)*dt/6;
      y = y0+(fy0+2*fy1+2*fy2+fy3)*dt/6;
      z = z0+(fz0+2*fz1+2*fz2+fz3)*dt/6;

      fx4 = a*(y-x);
      fy4 = r*x-y-x*z;
      fz4 = x*y-b*z;
      t = t+dt;
      x0 = x;
      y0 = y;
      z0 = z; 

      if(m != 1){
        if( m != 0){
        printf("\nError: m is %d\n", m);
        goto end;
        }
      }

      if (m == 0){
        printf("%lf %lf %d\n", t, x0, m);
        fprintf(fchaos, "%lf %lf\n", t, x0);
      }
      if (m == 1) {
        printf("%lf %lf %d\n", y0, z0, m);
        fprintf(fchaos, "%lf %lf %lf\n", x0, y0, z0);
      }
  }
    end:
    exit(0);
}
