/* Covert nan to zero. */

#include <rsf.h>

#include <math.h>

int main(int argc, char* argv[])
{
    bool nan;
    int n1, n2, ii;
    float value, *xx;
    sf_file in, out;

    sf_init(argc,argv);
    in = sf_input("in");
    out = sf_output("out");

    if (SF_FLOAT != sf_gettype(in)) sf_error("Need float input");
    if (!sf_histint(in,"n1",&n1)) sf_error("No n1= in input");
    if (!sf_histint(in,"n2",&n2)) sf_error("No n2= in input");

    xx = sf_floatalloc(n1*n2);

    if (!sf_getfloat("value",&value)) value=0.0;
    sf_putint(out,"n1",n1);
    sf_putint(out,"n2",n2);
    sf_floatread(xx,n1*n2,in);
    for (ii=0; ii < n1*n2;ii++){
       nan = (bool) isnan(xx[ii]);
       if(nan){
         xx[ii] = value;
       }
    }
    sf_floatwrite (xx,n1*n2,out);
    exit(0);
}

