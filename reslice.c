#define _reslice

#include <stdlib.h>
#include <stdio.h>
#include "babak_lib.h"

#define LIN 1
#define NEARN 2
#define SINC 3
#define CUBICSPLINE 4

static float v1,v2,v3,v4;
static float w1,w2;

unsigned char linearInterpolator(float x, float y, float z, unsigned char *array, int nx, int ny, int nz, int np);
short linearInterpolator(float x, float y, float z, short *array, int nx, int ny, int nz, int np);
float linearInterpolator(float x, float y, float z, float *array, int nx, int ny, int nz, int np);

// warning: T will be altered.
float *resliceImage(float *im1, int nx1, int ny1, int nz1, float dx1, float dy1, float dz1, 
int nx2, int ny2, int nz2, float dx2, float dy2, float dz2, float *T);

char *resliceImage(char *obj, int Onx, int Ony, float Odx, float Ody, int Tnx, int Tny, float Tdx, float Tdy, float *T);
short *resliceImage(short *obj, int Onx, int Ony, float Odx, float Ody, int Tnx, int Tny, float Tdx, float Tdy, float *T);
short *resliceImage(float *obj, int Onx, int Ony, float Odx, float Ody, int Tnx, int Tny, float Tdx, float Tdy, float *T);

short nearestNeighbor	(float x, float y, float z, short *array, int nx, int ny, int nz, int np);
unsigned char nearestNeighbor	(float x, float y, float z, unsigned char *array, int nx, int ny, int nz, int np);

float linearInterpolator(float x, float y, float z, float *array, int nx, int ny, int nz, int np, float *w);
unsigned char linearInterpolator(float x, float y, float z, unsigned char *array, int nx, int ny, int nz, int np, float *w);

short linearInterpolator(float x, float y, short *array, int nx, int ny);
short linearInterpolator(float x, float y, float *array, int nx, int ny);
char linearInterpolator(float x, float y, char *array, int nx, int ny);

char *resliceImage(char *obj, int Onx, int Ony, float Odx, float Ody, int Tnx, int Tny, float Tdx, float Tdy, float *T)
{
	float Oxc,Oyc; 
	float Txc,Tyc; 
	float Ax;
	float Ay;
  	float xx,yy; /* translation parameters */
  	float x,y;   

	int i,j;     /* loop index */
	int q;

	char *trg;

	trg=(char *)calloc(Tnx*Tny,sizeof(char));

	Txc=Tdx*(Tnx-1)/2.0;     /* +---+---+ */
	Tyc=Tdy*(Tny-1)/2.0;

	Oxc=Odx*(Onx-1)/2.0;      /* +---+---+ */
	Oyc=Ody*(Ony-1)/2.0;

	q=0;
	for(j=0;j<Tny;j++) 
	{
   		yy=j*Tdy-Tyc;
		Ax=T[1]*yy+T[2];
		Ay=T[4]*yy+T[5];

  		for(i=0;i<Tnx;i++) 
		{
       		xx=i*Tdx-Txc;

       		x=T[0]*xx+Ax;
    	   	y=T[3]*xx+Ay;
		
			x = (x+Oxc)/Odx;
			y = (y+Oyc)/Ody;

	    	trg[q++]=linearInterpolator(x,y,obj,Onx,Ony);
		}
	}

	return( trg );
}

// warning: T will be altered.
short *resliceImage(short *obj, int Onx, int Ony, float Odx, float Ody, int Tnx, int Tny, float Tdx, float Tdy, float *T)
{
	float Oxc,Oyc; 
	float Txc,Tyc; 
	float Ax;
	float Ay;
  	float xx,yy; /* translation parameters */
  	float x,y;   

	int i,j;     /* loop index */
	int q;

	short *trg;

	trg=(short *)calloc(Tnx*Tny,sizeof(short));

	Txc=Tdx*(Tnx-1)/2.0;     /* +---+---+ */
	Tyc=Tdy*(Tny-1)/2.0;

	Oxc=Odx*(Onx-1)/2.0;      /* +---+---+ */
	Oyc=Ody*(Ony-1)/2.0;

	q=0;
	for(j=0;j<Tny;j++) 
	{
   		yy=j*Tdy-Tyc;
		Ax=T[1]*yy+T[2];
		Ay=T[4]*yy+T[5];

  		for(i=0;i<Tnx;i++) 
		{
       		xx=i*Tdx-Txc;

       		x=T[0]*xx+Ax;
    	   	y=T[3]*xx+Ay;
		
			x = (x+Oxc)/Odx;
			y = (y+Oyc)/Ody;

	    	trg[q++]=linearInterpolator(x,y,obj,Onx,Ony);
		}
	}

	return( trg );
}

short *resliceImage(float *obj, int Onx, int Ony, float Odx, float Ody, int Tnx, int Tny, float Tdx, float Tdy, float *T)
{
	float Oxc,Oyc; 
	float Txc,Tyc; 
	float Ax;
	float Ay;
  	float xx,yy; /* translation parameters */
  	float x,y;   

	int i,j;     /* loop index */
	int q;

	short *trg;

	trg=(short *)calloc(Tnx*Tny,sizeof(short));

	Txc=Tdx*(Tnx-1)/2.0;     /* +---+---+ */
	Tyc=Tdy*(Tny-1)/2.0;

	Oxc=Odx*(Onx-1)/2.0;      /* +---+---+ */
	Oyc=Ody*(Ony-1)/2.0;

	q=0;
	for(j=0;j<Tny;j++) 
	{
   		yy=j*Tdy-Tyc;
		Ax=T[1]*yy+T[2];
		Ay=T[4]*yy+T[5];

  		for(i=0;i<Tnx;i++) 
		{
       		xx=i*Tdx-Txc;

       		x=T[0]*xx+Ax;
    	   	y=T[3]*xx+Ay;

			x = (x+Oxc)/Odx;
			y = (y+Oyc)/Ody;

	    	trg[q++]=linearInterpolator(x,y,obj,Onx,Ony);
		}
	}

	return( trg );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// warning: T will be altered.
short *resliceImage(short *im1, int nx1, int ny1, int nz1, float dx1, float dy1, float dz1, 
int nx2, int ny2, int nz2, float dx2, float dy2, float dz2, float *T, int interpolation_method)
{
	float xc1,yc1,zc1; 
	float xc2,yc2,zc2; 
	float Ax,Bx;
	float Ay,By;
	float Az,Bz;
  	float xx,yy,zz; /* translation parameters */
  	float x,y,z;   

	int i,j,k;     /* loop index */

	int q;
	int np2,nv2;
	int np1;

	short *im2;

    float *beta, del;
    float *c;

   if(interpolation_method == CUBICSPLINE)
   {
      beta=computeBeta(&del);
      c = (float *)calloc(nx1*ny1*nz1, sizeof(float));
      cubicSplineAnalysis(im1, c, nx1, ny1, nz1);
   }

	np2=nx2*ny2;
	nv2=np2*nz2;

	im2=(short *)calloc(nv2,sizeof(short));

	xc2=dx2*(nx2-1)/2.0;     /* +---+---+ */
	yc2=dy2*(ny2-1)/2.0;
	zc2=dz2*(nz2-1)/2.0;

	np1=nx1*ny1;

	xc1=dx1*(nx1-1)/2.0;      /* +---+---+ */
	yc1=dy1*(ny1-1)/2.0;
	zc1=dz1*(nz1-1)/2.0;

	T[0] /= dx1;
	T[1] /= dx1;
	T[2] /= dx1;
	T[3] /= dx1;
	T[3] += xc1/dx1;

	T[4] /= dy1;
	T[5] /= dy1;
	T[6] /= dy1;
	T[7] /= dy1;
	T[7] += yc1/dy1;

	T[8]  /= dz1;
	T[9]  /= dz1;
	T[10] /= dz1;
	T[11] /= dz1;
	T[11] += zc1/dz1;

    if(interpolation_method == LIN)
        interpolator=linearInterpolator;
    else if(interpolation_method == NEARN)
        interpolator=nearestNeighbor;

	q=0;
	for(k=0;k<nz2;k++) 
	{
  		zz=k*dz2-zc2;
	  	Bx=T[2]*zz+T[3];
	  	By=T[6]*zz+T[7];
		Bz=T[10]*zz+T[11];
		for(j=0;j<ny2;j++) 
		{
     		yy=j*dy2-yc2;
			Ax=T[1]*yy+Bx;
			Ay=T[5]*yy+By;
			Az=T[9]*yy+Bz;

  			for(i=0;i<nx2;i++) 
			{
        		xx=i*dx2-xc2;

           		x=T[0]*xx+Ax;
	    	   	y=T[4]*xx+Ay;
	    	   	z=T[8]*xx+Az;

                if(interpolation_method == LIN )
                {
				   im2[q++]=linearInterpolator(x,y,z,im1,nx1,ny1,nz1,np1);
                }
                else if(interpolation_method == NEARN)
                {
				   im2[q++]=nearestNeighbor(x,y,z,im1,nx1,ny1,nz1,np1);
                }
                else if(interpolation_method == CUBICSPLINE)
                {
                   im2[q++] = (short)(cubicSplineSynthesis(c, nx1, ny1, nz1, x, y, z, beta, del)+0.5);
                }
			}
		}
	}

   if(interpolation_method == CUBICSPLINE)
   {
      free(beta);
      free(c);
   }

   return( im2 );
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////
// warning: T will be altered.
unsigned char *resliceImage(unsigned char *im1, int nx1, int ny1, int nz1, float dx1, float dy1, float dz1, 
int nx2, int ny2, int nz2, float dx2, float dy2, float dz2, float *T)
{
	float xc1,yc1,zc1; 
	float xc2,yc2,zc2; 
	float Ax,Bx;
	float Ay,By;
	float Az,Bz;
  	float xx,yy,zz; /* translation parameters */
  	float x,y,z;   

	int i,j,k;     /* loop index */

	int q;
	int np2,nv2;
	int np1;

	unsigned char *im2;

	np2=nx2*ny2;
	nv2=np2*nz2;

	im2=(unsigned char *)calloc(nv2,1);

	xc2=dx2*(nx2-1)/2.0;     /* +---+---+ */
	yc2=dy2*(ny2-1)/2.0;
	zc2=dz2*(nz2-1)/2.0;

	np1=nx1*ny1;

	xc1=dx1*(nx1-1)/2.0;      /* +---+---+ */
	yc1=dy1*(ny1-1)/2.0;
	zc1=dz1*(nz1-1)/2.0;

	T[0] /= dx1;
	T[1] /= dx1;
	T[2] /= dx1;
	T[3] /= dx1;
	T[3] += xc1/dx1;

	T[4] /= dy1;
	T[5] /= dy1;
	T[6] /= dy1;
	T[7] /= dy1;
	T[7] += yc1/dy1;

	T[8]  /= dz1;
	T[9]  /= dz1;
	T[10] /= dz1;
	T[11] /= dz1;
	T[11] += zc1/dz1;


	q=0;
	for(k=0;k<nz2;k++) 
	{
  		zz=k*dz2-zc2;
	  	Bx=T[2]*zz+T[3];
	  	By=T[6]*zz+T[7];
		Bz=T[10]*zz+T[11];
		for(j=0;j<ny2;j++) 
		{
     		yy=j*dy2-yc2;
			Ax=T[1]*yy+Bx;
			Ay=T[5]*yy+By;
			Az=T[9]*yy+Bz;

  			for(i=0;i<nx2;i++) 
			{
        		xx=i*dx2-xc2;

           		x=T[0]*xx+Ax;
	    	   	y=T[4]*xx+Ay;
	    	   	z=T[8]*xx+Az;

				im2[q++]=linearInterpolator(x,y,z,im1,nx1,ny1,nz1,np1);
			}
		}
	}

	return( im2 );
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

// warning: T will be altered.
short *resliceImage(short *im1, DIM dim1, DIM dim2, float *T, int interpolation_method)
{
	float xc1,yc1,zc1; 
	float xc2,yc2,zc2; 
	float Ax,Bx;
	float Ay,By;
	float Az,Bz;
  	float xx,yy,zz; /* translation parameters */
  	float x,y,z;   

	int i,j,k;     /* loop index */

	int q;
	int np2,nv2;
	int np1;

	short *im2;

	np2=dim2.nx*dim2.ny;
	nv2=np2*dim2.nz;

	im2=(short *)calloc(nv2,sizeof(short));

	xc2=dim2.dx*(dim2.nx-1)/2.0;     /* +---+---+ */
	yc2=dim2.dy*(dim2.ny-1)/2.0;
	zc2=dim2.dz*(dim2.nz-1)/2.0;

	np1=dim1.nx*dim1.ny;

	xc1=dim1.dx*(dim1.nx-1)/2.0;      /* +---+---+ */
	yc1=dim1.dy*(dim1.ny-1)/2.0;
	zc1=dim1.dz*(dim1.nz-1)/2.0;

	T[0] /= dim1.dx;
	T[1] /= dim1.dx;
	T[2] /= dim1.dx;
	T[3] /= dim1.dx;
	T[3] += xc1/dim1.dx;

	T[4] /= dim1.dy;
	T[5] /= dim1.dy;
	T[6] /= dim1.dy;
	T[7] /= dim1.dy;
	T[7] += yc1/dim1.dy;

	T[8]  /= dim1.dz;
	T[9]  /= dim1.dz;
	T[10] /= dim1.dz;
	T[11] /= dim1.dz;
	T[11] += zc1/dim1.dz;

    if(interpolation_method == LIN)
        interpolator=linearInterpolator;
    else if(interpolation_method == NEARN)
        interpolator=nearestNeighbor;

	q=0;
	for(k=0;k<dim2.nz;k++) 
	{
  		zz=k*dim2.dz-zc2;
	  	Bx=T[2]*zz+T[3];
	  	By=T[6]*zz+T[7];
		Bz=T[10]*zz+T[11];
		for(j=0;j<dim2.ny;j++) 
		{
     		yy=j*dim2.dy-yc2;
			Ax=T[1]*yy+Bx;
			Ay=T[5]*yy+By;
			Az=T[9]*yy+Bz;

  			for(i=0;i<dim2.nx;i++) 
			{
        		xx=i*dim2.dx-xc2;

           		x=T[0]*xx+Ax;
	    	   	y=T[4]*xx+Ay;
	    	   	z=T[8]*xx+Az;

				im2[q++]=interpolator(x,y,z,im1,dim1.nx,dim1.ny,dim1.nz,np1);

			}
		}
	}

	return( im2 );
}

// warning: T will be altered.
float *resliceImage(float *im1, int nx1, int ny1, int nz1, float dx1, float dy1, float dz1, 
int nx2, int ny2, int nz2, float dx2, float dy2, float dz2, float *T, float *w)
{
	float xc1,yc1,zc1; 
	float xc2,yc2,zc2; 
	float Ax,Bx;
	float Ay,By;
	float Az,Bz;
  	float xx,yy,zz; /* translation parameters */
  	float x,y,z;   

	int i,j,k;     /* loop index */

	int q;
	int np2,nv2;
	int np1;

	float *im2;

	np2=nx2*ny2;
	nv2=np2*nz2;

	im2=(float *)calloc(nv2,sizeof(float));

	xc2=dx2*(nx2-1)/2.0;     /* +---+---+ */
	yc2=dy2*(ny2-1)/2.0;
	zc2=dz2*(nz2-1)/2.0;

	np1=nx1*ny1;

	xc1=dx1*(nx1-1)/2.0;      /* +---+---+ */
	yc1=dy1*(ny1-1)/2.0;
	zc1=dz1*(nz1-1)/2.0;

	T[0] /= dx1;
	T[1] /= dx1;
	T[2] /= dx1;
	T[3] /= dx1;
	T[3] += xc1/dx1;

	T[4] /= dy1;
	T[5] /= dy1;
	T[6] /= dy1;
	T[7] /= dy1;
	T[7] += yc1/dy1;

	T[8]  /= dz1;
	T[9]  /= dz1;
	T[10] /= dz1;
	T[11] /= dz1;
	T[11] += zc1/dz1;

	q=0;
	for(k=0;k<nz2;k++) 
	{
  		zz=k*dz2-zc2;
	  	Bx=T[2]*zz+T[3];
	  	By=T[6]*zz+T[7];
		Bz=T[10]*zz+T[11];
		for(j=0;j<ny2;j++) 
		{
     		yy=j*dy2-yc2;
			Ax=T[1]*yy+Bx;
			Ay=T[5]*yy+By;
			Az=T[9]*yy+Bz;

  			for(i=0;i<nx2;i++) 
			{
        		xx=i*dx2-xc2;

           		x=T[0]*xx+Ax;
	    	   	y=T[4]*xx+Ay;
	    	   	z=T[8]*xx+Az;

		    	im2[q]=linearInterpolator(x,y,z,im1,nx1,ny1,nz1,np1,&w[q]);
				q++;
			}
		}
	}

	return( im2 );
}

unsigned char linearInterpolator(float x, float y, float z, unsigned char *array, int nx, int ny, int nz, int np)
{
	int     i,j,k,n;
	float   u,uu;
	
	i=(int)(x);
	j=(int)(y);
	k=(int)(z);

	if(i<0 || i>(nx-2) || j<0 || j>(ny-2) )
	{
		return(0);
	}

	if( k>=0 && k<(nz-1) )
	{
		u = x - i; if(u<0.0) u=0.0;
		uu = 1.0-u;

		n=k*np + j*nx +i;
		v1 = array[n]*uu + array[n+1]*u;
		v2 = array[n+nx]*uu + array[n+nx+1]*u;
		v3 = array[n+np]*uu + array[n+np+1]*u;
		v4 = array[n+np+nx]*uu + array[n+np+nx+1]*u;

		u = y - j; if(u<0.0) u=0.0;
		uu = 1.0-u;
		w1 = v1*uu + v2*u;
		w2 = v3*uu + v4*u;

		u = z - k; if(u<0.0) u=0.0;
		return( (unsigned char)( w1*(1.0-u) + w2*u  + 0.5) );
	}

	if( k==(nz-1) )
	{
		u = x - i; if(u<0.0) u=0.0;
		uu = 1.0-u;

		n=k*np + j*nx +i;
		v1 = array[n]*uu + array[n+1]*u;

		n=k*np + (j+1)*nx +i;
		v2 = array[n]*uu + array[n+1]*u;

		u = y - j; if(u<0.0) u=0.0;
		return( (unsigned char)( v1*(1.0-u) + v2*u  + 0.5) );
	}

	return(0);
}

short linearInterpolator(float x, float y, float z, short *array, int nx, int ny, int nz, int np)
{
	int     i,j,k,n;
	float   u,uu;
	
	i=(int)(x);
	j=(int)(y);
	k=(int)(z);

	if(i<0 || i>(nx-2) || j<0 || j>(ny-2) )
	{
		return(0);
	}

	if( k>=0 && k<(nz-1) )
	{
		u = x - i; if(u<0.0) u=0.0;
		uu = 1.0-u;

		n=k*np + j*nx +i;
		v1 = array[n]*uu + array[n+1]*u;
		v2 = array[n+nx]*uu + array[n+nx+1]*u;
		v3 = array[n+np]*uu + array[n+np+1]*u;
		v4 = array[n+np+nx]*uu + array[n+np+nx+1]*u;

		u = y - j; if(u<0.0) u=0.0;
		uu = 1.0-u;
		w1 = v1*uu + v2*u;
		w2 = v3*uu + v4*u;

		u = z - k; if(u<0.0) u=0.0;
		return( (short)( w1*(1.0-u) + w2*u  + 0.5) );
	}

	if( k==(nz-1) )
	{
		u = x - i; if(u<0.0) u=0.0;
		uu = 1.0-u;

		n=k*np + j*nx +i;
		v1 = array[n]*uu + array[n+1]*u;

		n=k*np + (j+1)*nx +i;
		v2 = array[n]*uu + array[n+1]*u;

		u = y - j; if(u<0.0) u=0.0;
		return( (short)( v1*(1.0-u) + v2*u  + 0.5) );
	}

	return(0);
}

float linearInterpolator(float x, float y, float z, float *array, int nx, int ny, int nz, int np, float *w)
{
	int     i,j,k,n;
	float   u,uu;
	float   v,vv;
	float   s,ss;
	
	i=(int)(x);
	j=(int)(y);
	k=(int)(z);

	*w = 0.0;

	if(i<0 || i>(nx-2) || j<0 || j>(ny-2) ) return(0);

	if( k>=0 && k<(nz-1) )
	{
		u = x - i; if(u<0.0) u=0.0;
		uu = 1.0-u;
		n=k*np + j*nx +i;
		v1 = array[n]*uu + array[n+1]*u;
		v2 = array[n+nx]*uu + array[n+nx+1]*u;
		v3 = array[n+np]*uu + array[n+np+1]*u;
		v4 = array[n+np+nx]*uu + array[n+np+nx+1]*u;

		v = y - j; if(v<0.0) v=0.0;
		vv = 1.0-v;
		w1 = v1*vv + v2*v;
		w2 = v3*vv + v4*v;

		s = z - k; if(s<0.0) s=0.0;
		ss = 1.0-s;

		*w = (u*v*s)*(u*v*s) + (u*v*ss)*(u*v*ss) + (u*vv*s)*(u*vv*s) + (u*vv*ss)*(u*vv*ss) +
		(uu*v*s)*(uu*v*s) + (uu*v*ss)*(uu*v*ss) + (uu*vv*s)*(uu*vv*s) + (uu*vv*ss)*(uu*vv*ss);

		return( w1*ss + w2*s );
	}

	if( k==(nz-1) )
	{
		u = x - i; if(u<0.0) u=0.0;
		uu = 1.0-u;

		n=k*np + j*nx +i;
		v1 = array[n]*uu + array[n+1]*u;

		n=k*np + (j+1)*nx +i;
		v2 = array[n]*uu + array[n+1]*u;

		v = y - j; if(v<0.0) v=0.0;
		vv = 1.0-v;

		*w = (u*v)*(u*v) + (u*vv)*(u*vv) + (uu*v)*(uu*v) + (uu*vv)*(uu*vv);

		return( v1*vv + v2*v );
	}

	return(0.0);
}

unsigned char linearInterpolator(float x, float y, float z, unsigned char *array, int nx, int ny, int nz, int np, float *w)
{
	int     i,j,k,n;
	float   u,uu;
	float   v,vv;
	float   s,ss;
	
	i=(int)(x);
	j=(int)(y);
	k=(int)(z);

	*w = 0.0;

	if(i<0 || i>(nx-2) || j<0 || j>(ny-2) ) return(0);

	if( k>=0 && k<(nz-1) )
	{
		u = x - i; if(u<0.0) u=0.0;
		uu = 1.0-u;
		n=k*np + j*nx +i;
		v1 = array[n]*uu + array[n+1]*u;
		v2 = array[n+nx]*uu + array[n+nx+1]*u;
		v3 = array[n+np]*uu + array[n+np+1]*u;
		v4 = array[n+np+nx]*uu + array[n+np+nx+1]*u;

		v = y - j; if(v<0.0) v=0.0;
		vv = 1.0-v;
		w1 = v1*vv + v2*v;
		w2 = v3*vv + v4*v;

		s = z - k; if(s<0.0) s=0.0;
		ss = 1.0-s;

		*w = (u*v*s)*(u*v*s) + (u*v*ss)*(u*v*ss) + (u*vv*s)*(u*vv*s) + (u*vv*ss)*(u*vv*ss) +
		(uu*v*s)*(uu*v*s) + (uu*v*ss)*(uu*v*ss) + (uu*vv*s)*(uu*vv*s) + (uu*vv*ss)*(uu*vv*ss);

		return( (unsigned char)(w1*ss + w2*s + 0.5) );
	}

	if( k==(nz-1) )
	{
		u = x - i; if(u<0.0) u=0.0;
		uu = 1.0-u;

		n=k*np + j*nx +i;
		v1 = array[n]*uu + array[n+1]*u;

		n=k*np + (j+1)*nx +i;
		v2 = array[n]*uu + array[n+1]*u;

		v = y - j; if(v<0.0) v=0.0;
		vv = 1.0-v;

		*w = (u*v)*(u*v) + (u*vv)*(u*vv) + (uu*v)*(uu*v) + (uu*vv)*(uu*vv);

		return( (unsigned char)(v1*vv + v2*v + 0.5) );
	}

	return(0);
}

/*
 * old version before optimization
float linearInterpolator(float x, float y, float z, float *array, int nx, int ny, int nz, int np)
{
   int     i,j,k,n;
   float   v1,v2,v3,v4,w1,w2;
   float   u,uu;

   i=(int)(x);
   j=(int)(y);
   k=(int)(z);

   if(i<0 || i>(nx-2) || j<0 || j>(ny-2) )
   {
      return(0.0);
   }

   if( k>=0 && k<(nz-1) )
   {
      u = x - i; if(u<0.0) u=0.0;
      uu = 1.0-u;

      n= k*np + j*nx + i;

      v1 = array[n]*uu + array[n+1]*u;
      v2 = array[n+nx]*uu + array[n+nx+1]*u;
      v3 = array[n+np]*uu + array[n+np+1]*u;
      v4 = array[n+np+nx]*uu + array[n+np+nx+1]*u;

      u = y - j; if(u<0.0) u=0.0;
      uu = 1.0-u;
      w1 = v1*uu + v2*u;
      w2 = v3*uu + v4*u;

      u = z - k; if(u<0.0) u=0.0;
      return( w1*(1.0-u) + w2*u );
   }
   else if( k==(nz-1) )
   {
      u = x - i; if(u<0.0) u=0.0;
      uu = 1.0-u;

      n=k*np + j*nx +i;
      v1 = array[n]*uu + array[n+1]*u;

      n=k*np + (j+1)*nx +i;
      v2 = array[n]*uu + array[n+1]*u;

      u = y - j; if(u<0.0) u=0.0;
      return( v1*(1.0-u) + v2*u );
   }

   return(0.0);
}
*/

float linearInterpolator(float x, float y, float z, float *array, int nx, int ny, int nz, int np)
{
   int n_and_nx;  // n + nx
   int n_and_np;  // n + np;

   int   i,j,k,n;
   float u1,u2,u3,u4,u5,u6,u7,u8;
   float v1,v2,v3,v4;
   float w1,w2;
   float xr;
   float yr;
   float zr;

   i=(int)(x);
   j=(int)(y);
   k=(int)(z);

   if(i<0 || i>(nx-2) || j<0 || j>(ny-2) )
   {
      return(0.0);
   }

   if( k>=0 && k<(nz-1) )
   {
      xr = x - i;

      n= k*np + j*nx + i;

      n_and_nx = n + nx;
      n_and_np = n + np;

      u1 = array[n]; 
      u2 = array[n+1]; 
      u3 = array[n_and_nx];
      u4 = array[n_and_nx + 1];
      u5 = array[n_and_np];
      u6 = array[n_and_np + 1];
      u7 = array[n_and_nx + np];
      u8 = array[n_and_nx + np + 1];

      v1 = u1 + (u2-u1)*xr;
      v2 = u3 + (u4-u3)*xr;
      v3 = u5 + (u6-u5)*xr;
      v4 = u7 + (u8-u7)*xr;

      yr = y - j;
      w1 = v1 + (v2-v1)*yr;
      w2 = v3 + (v4-v3)*yr;

      return( w1 + (w2-w1)*(z-k) ); // saved a multiplication :)
   }
   else if( k==(nz-1) )
   {
      xr = x - i;

      n=k*np + j*nx +i;

      v1 = array[n];
      v2 = array[n+1];
      w1 = v1 + (v2-v1)*xr;

      n += nx;

      v1 = array[n];
      v2 = array[n+1];

      w2 = v1 + (v2-v1)*xr;

      return( w1 + (w2-w1)*(y-j) );
   }

   return(0.0);
}

short linearInterpolator(float x, float y, short *array, int nx, int ny)
{
   int i,j,n;
   float u,uu;
   float v1, v2;
	
   i=(int)(x);
   j=(int)(y);

   if(i<0 || i>(nx-2) || j<0 || j>(ny-2) ) 
   {
      return(0);
   }

   u = x - i; if(u<0.0) u=0.0;
   uu = 1.0-u;

   n= j*nx +i;
   v1 = array[n]*uu + array[n+1]*u;
   v2 = array[n+nx]*uu + array[n+nx+1]*u;

   u = y - j; if(u<0.0) u=0.0;
   uu = 1.0-u;

   return( (short)( v1*uu + v2*u + 0.5 ) );
}

short linearInterpolator(float x, float y, float *array, int nx, int ny)
{
   int     i,j,n;
   float   u,uu;
   float v1, v2;
	
   i=(int)(x);
   j=(int)(y);

   if(i<0 || i>(nx-2) || j<0 || j>(ny-2) ) 
   {
      return(0);
   }

   u = x - i; if(u<0.0) u=0.0;
   uu = 1.0-u;

   n= j*nx +i;
   v1 = array[n]*uu + array[n+1]*u;
   v2 = array[n+nx]*uu + array[n+nx+1]*u;

   u = y - j; if(u<0.0) u=0.0;
   uu = 1.0-u;

   return( (short)( v1*uu + v2*u + 0.5 ) );
}

char linearInterpolator(float x, float y, char *array, int nx, int ny)
{
	int     i,j,n;
	float   u,uu;
	
	i=(int)(x);
	j=(int)(y);

	if(i<0 || i>(nx-2) || j<0 || j>(ny-2) ) return(0);

	u = x - i; if(u<0.0) u=0.0;
	uu = 1.0-u;

	n= j*nx +i;
	v1 = array[n]*uu + array[n+1]*u;
	v2 = array[n+nx]*uu + array[n+nx+1]*u;

	u = y - j; if(u<0.0) u=0.0;
	uu = 1.0-u;

	return( (char)( v1*uu + v2*u + 0.5 ) );
}

short *resliceImage(short *im1, int nx1, int ny1, int nz1, float dx1, float dy1, float dz1,
int nx2, int ny2, int nz2, float dx2, float dy2, float dz2, float *Xwarp, float *Ywarp, float *Zwarp)
{
  	float  x,y,z;   
  	float  xx,yy,zz;   
	int q;
	int np1;
	short *im2;
	float xc1, yc1, zc1;
	float xc2, yc2, zc2;
	float *beta, del;
	float *c;

	np1=nx1*ny1;

	im2=(short *)calloc(nx2*ny2*nz2,sizeof(short));

	xc1=dx1*(nx1-1)/2.0;     /* +---+---+ */
	yc1=dy1*(ny1-1)/2.0;
	zc1=dz1*(nz1-1)/2.0;

   	xc2=dx2*(nx2-1)/2.0;     /* +---+---+ */
	yc2=dy2*(ny2-1)/2.0;
	zc2=dz2*(nz2-1)/2.0;

	q=0;
	for(int k=0;k<nz2;k++) 
	{
		for(int j=0;j<ny2;j++) 
		{
  			for(int i=0;i<nx2;i++) 
			{
				zz = k*dz2 - zc2 + Zwarp[q];
				yy = j*dy2 - yc2 + Ywarp[q];
				xx = i*dx2 - xc2 + Xwarp[q];

				x = ( xx + xc1 )/dx1;
				y = ( yy + yc1 )/dy1;
				z = ( zz + zc1 )/dz1;

	   			im2[q++]=linearInterpolator(x,y,z,im1,nx1,ny1,nz1,np1);
			}
		}
	}

	return( im2 );
}

short *computeReslicedImage(short *im1, int nx1, int ny1, int nz1, float dx1, float dy1, float dz1,
int nx2, int ny2, int nz2, float dx2, float dy2, float dz2, float *Xwarp, float *Ywarp, float *Zwarp)
{
  	float  x,y,z;   
	int q;
	int np1;
	short *im2;
	float xc1, yc1, zc1;
	float xc2, yc2, zc2;

	np1=nx1*ny1;

	im2=(short *)calloc(nx2*ny2*nz2,sizeof(short));

	xc1=dx1*(nx1-1)/2.0;     /* +---+---+ */
	yc1=dy1*(ny1-1)/2.0;
	zc1=dz1*(nz1-1)/2.0;

   	xc2=dx2*(nx2-1)/2.0;     /* +---+---+ */
	yc2=dy2*(ny2-1)/2.0;
	zc2=dz2*(nz2-1)/2.0;

	q=0;
	for(int k=0;k<nz2;k++) 
	for(int j=0;j<ny2;j++) 
  	for(int i=0;i<nx2;i++) 
	{
		z = (k*dz2 - zc2 + Zwarp[q] + zc1) /dz1;
		y = (j*dy2 - yc2 + Ywarp[q] + yc1) /dy1;
		x = (i*dx2 - xc2 + Xwarp[q] + xc1) /dx1;

		im2[q++]=linearInterpolator(x,y,z,im1,nx1,ny1,nz1,np1);
	}

	return( im2 );
}

float *computeReslicedImage(float *im1, int nx1, int ny1, int nz1, float dx1, float dy1, float dz1,
int nx2, int ny2, int nz2, float dx2, float dy2, float dz2, float *Xwarp, float *Ywarp, float *Zwarp)
{
  	float  x,y,z;   
	int q;
	int np1;
	float *im2;
	float xc1, yc1, zc1;
	float xc2, yc2, zc2;

	np1=nx1*ny1;

	im2=(float *)calloc(nx2*ny2*nz2,sizeof(float));

	xc1=dx1*(nx1-1)/2.0;     /* +---+---+ */
	yc1=dy1*(ny1-1)/2.0;
	zc1=dz1*(nz1-1)/2.0;

   	xc2=dx2*(nx2-1)/2.0;     /* +---+---+ */
	yc2=dy2*(ny2-1)/2.0;
	zc2=dz2*(nz2-1)/2.0;

	q=0;
	for(int k=0;k<nz2;k++) 
	for(int j=0;j<ny2;j++) 
  	for(int i=0;i<nx2;i++) 
	{
		z = (k*dz2 - zc2 + Zwarp[q] + zc1) /dz1;
		y = (j*dy2 - yc2 + Ywarp[q] + yc1) /dy1;
		x = (i*dx2 - xc2 + Xwarp[q] + xc1) /dx1;

		im2[q++]=linearInterpolator(x,y,z,im1,nx1,ny1,nz1,np1);
	}

	return( im2 );
}

short *computeReslicedImage(short *im1, int nx1, int ny1, float dx1, float dy1, 
int nx2, int ny2, float dx2, float dy2, float *Xwarp, float *Ywarp)
{
  	float  x,y;   
	int q;
	short *im2;
	float xc1, yc1;
	float xc2, yc2;

	im2=(short *)calloc(nx2*ny2,sizeof(short));

	xc1=dx1*(nx1-1)/2.0;     /* +---+---+ */
	yc1=dy1*(ny1-1)/2.0;

   	xc2=dx2*(nx2-1)/2.0;     /* +---+---+ */
	yc2=dy2*(ny2-1)/2.0;

	q=0;
	for(int j=0;j<ny2;j++) 
	{
  		for(int i=0;i<nx2;i++) 
		{
				y = (j*dy2 - yc2 + Ywarp[q] + yc1) /dy1;
        		x = (i*dx2 - xc2 + Xwarp[q] + xc1) /dx1;

		    	im2[q++]=linearInterpolator(x,y,im1,nx1,ny1);
		}
	}

	return( im2 );
}

short *computeReslicedImage(float *im1, int nx1, int ny1, float dx1, float dy1, 
int nx2, int ny2, float dx2, float dy2, float *Xwarp, float *Ywarp)
{
  	float  x,y;   
	int q;
	short *im2;
	float xc1, yc1;
	float xc2, yc2;

	im2=(short *)calloc(nx2*ny2,sizeof(short));

	xc1=dx1*(nx1-1)/2.0;     /* +---+---+ */
	yc1=dy1*(ny1-1)/2.0;

   	xc2=dx2*(nx2-1)/2.0;     /* +---+---+ */
	yc2=dy2*(ny2-1)/2.0;

	q=0;
	for(int j=0;j<ny2;j++) 
	{
  		for(int i=0;i<nx2;i++) 
		{
				y = (j*dy2 - yc2 + Ywarp[q] + yc1) /dy1;
        		x = (i*dx2 - xc2 + Xwarp[q] + xc1) /dx1;

		    	im2[q++]=linearInterpolator(x,y,im1,nx1,ny1);
		}
	}

	return( im2 );
}

float nearestNeighbor(float x, float y, float z, float *array, int nx, int ny, int nz, int np)
{
   int     i,j,k;
  
   i=(int)(x+0.5);
   j=(int)(y+0.5);
   k=(int)(z+0.5);

   if( i>=0 && i<nx && j>=0 && j<ny && k>=0 && k<nz)
   {
      return(array[ np*k + nx*j +i ]);
   }
   else
   {
      return(0);
   }
}

short nearestNeighbor(float x, float y, float z, short *array, int nx, int ny, int nz, int np)
{
   int     i,j,k;
  
   i=(int)(x+0.5);
   j=(int)(y+0.5);
   k=(int)(z+0.5);

   if( i>=0 && i<nx && j>=0 && j<ny && k>=0 && k<nz)
   {
      return(array[ np*k + nx*j +i ]);
   }
   else
   {
      return(0);
   }
}

unsigned char nearestNeighbor(float x, float y, float z, unsigned char *array, int nx, int ny, int nz, int np)
{
   int     i,j,k;
  
   i=(int)(x+0.5);
   j=(int)(y+0.5);
   k=(int)(z+0.5);

   if( i>=0 && i<nx && j>=0 && j<ny && k>=0 && k<nz)
   {
      return(array[ np*k + nx*j +i ]);
   }
   else
   {
      return(0);
   }
}

// you must initialize drand48 before using this function
unsigned char PNN(float x, float y, float z, unsigned char *array, int nx, int ny, int nz)
{
	int   i,j,k,n;
	float u,uu;
	float v,vv;
	float s,ss;
	float P0, P1, P2, P3, P4, P5, P6, P7, P8;
	float r;
	int np, nv;

	np = nx*ny;
	nv = np*nz;
	
	i=(int)(x);
	j=(int)(y);
	k=(int)(z);

	if(i<0 || i>(nx-2) || j<0 || j>(ny-2) ) return(0);

	r = (float)drand48();

	if( k>=0 && k<(nz-1) )
	{
		u = x - i; if(u<0.0) u=0.0;
		uu = 1.0-u;

		v = y - j; if(v<0.0) v=0.0;
		vv = 1.0-v;

		s = z - k; if(s<0.0) s=0.0;
		ss = 1.0-s;

		P0 = 0.0;
		P1 = P0 + u*v*s;
		P2 = P1 + u*v*ss;
		P3 = P2 + u*vv*s; 
		P4 = P3 + u*vv*ss; 
		P5 = P4 + uu*v*s; 
		P6 = P5 + uu*v*ss; 
		P7 = P6 + uu*vv*s;
		P8 = P7 + uu*vv*ss;

		n = 0;
		if(r<P1) 		n=(k+1)*np + (j+1)*nx + (i+1);
		else if(r<P2) 	n=    k*np + (j+1)*nx + (i+1);
		else if(r<P3)	n=(k+1)*np +     j*nx + (i+1);
		else if(r<P4)	n=    k*np +     j*nx + (i+1);
		else if(r<P5)	n=(k+1)*np + (j+1)*nx + i;
		else if(r<P6)	n=    k*np + (j+1)*nx + i;
		else if(r<P7)	n=(k+1)*np +     j*nx + i;
		else if(r<P8)	n=    k*np +     j*nx + i;

		if(n>=0 && n<nv) return(array[n]); else return(0);
	}

	if( k==(nz-1) )
	{
		u = x - i; if(u<0.0) u=0.0;
		uu = 1.0-u;

		v = y - j; if(v<0.0) v=0.0;
		vv = 1.0-v;

		P0 = 0.0;
		P1 = P0 + u*v;
		P2 = P1 + u*vv;
		P3 = P2 + uu*v;
		P4 = P3 + uu*vv;

		if(r<P1) 		n=k*np + (j+1)*nx + (i+1);
		else if(r<P2)	n=k*np +     j*nx + (i+1); 	
		else if(r<P3)	n=k*np + (j+1)*nx + i;
		else if(r<P4)	n=k*np +     j*nx + i;

		if(n>=0 && n<nv) return(array[n]); else return(0);
	}

	return(0);
}

float partial_var(float x, float y, float z, unsigned char *array, int nx, int ny, int nz, int np, float mu)
{
	float  	var=0.0;
	float 	val;
	int     i,j,k,n;
	float   u,uu;
	float   v,vv;
	float   s,ss;
	
	i=(int)(x);
	j=(int)(y);
	k=(int)(z);

	if(i<0 || i>(nx-2) || j<0 || j>(ny-2) ) return(0.0);

	if( k>=0 && k<(nz-1) )
	{
		u = x - i; if(u<0.0) u=0.0;
		uu = 1.0-u;

		v = y - j; if(v<0.0) v=0.0;
		vv = 1.0-v;

		s = z - k; if(s<0.0) s=0.0;
		ss = 1.0-s;

		val = array[ k*np + j*nx + i] - mu;
		var += (uu*vv*ss)*val*val;

		val = array[ (k+1)*np + j*nx + i] - mu;
		var += (uu*vv*s)*val*val;

		val = array[ k*np + (j+1)*nx + i] - mu;
		var += (uu*v*ss)*val*val;

		val = array[ (k+1)*np + (j+1)*nx + i] - mu;
		var += (uu*v*s)*val*val;

		val = array[ k*np + j*nx + i+1] - mu;
		var += (u*vv*ss)*val*val;

		val = array[ (k+1)*np + j*nx + i+1] - mu;
		var += (u*vv*s)*val*val;

		val = array[ k*np + (j+1)*nx + i+1] - mu;
		var += (u*v*ss)*val*val;

		val = array[ (k+1)*np + (j+1)*nx + i+1] - mu;
		var += (u*v*s)*val*val;

		return(var);
	}

	if( k==(nz-1) )
	{
		u = x - i; if(u<0.0) u=0.0;
		uu = 1.0-u;

		v = y - j; if(v<0.0) v=0.0;
		vv = 1.0-v;

		val = array[ k*np + (j+1)*nx + i+1] - mu;
		var += (u*v)*val*val;

		val = array[ k*np + j*nx + i+1] - mu;
		var += (u*vv)*val*val;

		val = array[ k*np + (j+1)*nx + i] - mu;
		var += (uu*v)*val*val;

		val = array[ k*np + j*nx + i] - mu;
		var += (uu*vv)*val*val;

		return( var );
	}

	return(0.0);
}

// warning: T will be altered.
float *resliceImage(float *im1, int nx1, int ny1, int nz1, float dx1, float dy1, float dz1, 
int nx2, int ny2, int nz2, float dx2, float dy2, float dz2, float *T, float *xjit, float *yjit)
{
	float xc1,yc1,zc1; 
	float xc2,yc2,zc2; 
	float Ax,Bx;
	float Ay,By;
	float Az,Bz;
  	float xx,yy,zz; /* translation parameters */
  	float x,y,z;   

	int i,j,k;     /* loop index */

	int q;
	int np2,nv2;
	int np1;

	float *im2;

	np2=nx2*ny2;
	nv2=np2*nz2;

	im2=(float *)calloc(nv2,sizeof(float));

	xc2=dx2*(nx2-1)/2.0;     /* +---+---+ */
	yc2=dy2*(ny2-1)/2.0;
	zc2=dz2*(nz2-1)/2.0;

	np1=nx1*ny1;

	xc1=dx1*(nx1-1)/2.0;      /* +---+---+ */
	yc1=dy1*(ny1-1)/2.0;
	zc1=dz1*(nz1-1)/2.0;

	T[0] /= dx1;
	T[1] /= dx1;
	T[2] /= dx1;
	T[3] /= dx1;
	T[3] += xc1/dx1;

	T[4] /= dy1;
	T[5] /= dy1;
	T[6] /= dy1;
	T[7] /= dy1;
	T[7] += yc1/dy1;

	T[8]  /= dz1;
	T[9]  /= dz1;
	T[10] /= dz1;
	T[11] /= dz1;
	T[11] += zc1/dz1;

	q=0;
	for(k=0;k<nz2;k++) 
	{
  		zz=k*dz2-zc2;
	  	Bx=T[2]*zz+T[3];
	  	By=T[6]*zz+T[7];
		Bz=T[10]*zz+T[11];
		for(j=0;j<ny2;j++) 
		{
     		yy=(j + yjit[q]) *dy2-yc2;
			Ax=T[1]*yy+Bx;
			Ay=T[5]*yy+By;
			Az=T[9]*yy+Bz;

  			for(i=0;i<nx2;i++) 
			{
        		xx=(i + xjit[q]) *dx2-xc2;

           		x=T[0]*xx+Ax;
	    	   	y=T[4]*xx+Ay;
	    	   	z=T[8]*xx+Az;

		    	im2[q]=linearInterpolator(x,y,z,im1,nx1,ny1,nz1,np1);
				q++;
			}
		}
	}

	return( im2 );
}

// warning: T will be altered.
float *resliceImage(float *im1, int nx1, int ny1, int nz1, float dx1, float dy1, float dz1, 
int nx2, int ny2, int nz2, float dx2, float dy2, float dz2, float *T)
{
	float xc1,yc1,zc1; 
	float xc2,yc2,zc2; 
	float Ax,Bx;
	float Ay,By;
	float Az,Bz;
  	float xx,yy,zz; /* translation parameters */
  	float x,y,z;   

	int i,j,k;     /* loop index */

	int q;
	int np2,nv2;
	int np1;

	float *im2;

	np2=nx2*ny2;
	nv2=np2*nz2;

	im2=(float *)calloc(nv2,sizeof(float));

	xc2=dx2*(nx2-1)/2.0;     /* +---+---+ */
	yc2=dy2*(ny2-1)/2.0;
	zc2=dz2*(nz2-1)/2.0;

	np1=nx1*ny1;

	xc1=dx1*(nx1-1)/2.0;      /* +---+---+ */
	yc1=dy1*(ny1-1)/2.0;
	zc1=dz1*(nz1-1)/2.0;

	T[0] /= dx1;
	T[1] /= dx1;
	T[2] /= dx1;
	T[3] /= dx1;
	T[3] += xc1/dx1;

	T[4] /= dy1;
	T[5] /= dy1;
	T[6] /= dy1;
	T[7] /= dy1;
	T[7] += yc1/dy1;

	T[8]  /= dz1;
	T[9]  /= dz1;
	T[10] /= dz1;
	T[11] /= dz1;
	T[11] += zc1/dz1;

	q=0;
	for(k=0;k<nz2;k++) 
	{
  		zz=k*dz2-zc2;
	  	Bx=T[2]*zz+T[3];
	  	By=T[6]*zz+T[7];
		Bz=T[10]*zz+T[11];
		for(j=0;j<ny2;j++) 
		{
     		yy=j*dy2-yc2;
			Ax=T[1]*yy+Bx;
			Ay=T[5]*yy+By;
			Az=T[9]*yy+Bz;

  			for(i=0;i<nx2;i++) 
			{
        		xx=i*dx2-xc2;

           		x=T[0]*xx+Ax;
	    	   	y=T[4]*xx+Ay;
	    	   	z=T[8]*xx+Az;

		    	im2[q]=linearInterpolator(x,y,z,im1,nx1,ny1,nz1,np1);
				q++;
			}
		}
	}

	return( im2 );
}