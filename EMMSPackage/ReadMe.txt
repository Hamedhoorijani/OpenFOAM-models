EMMS drag model with a correlation of sphericity coefficient (phis) used in equations.
reference :  "EMMS drag model for simulating a gas–solid fluidized bed of geldart B particles: Effect of bed model parameters and polydispersity" by Kshetrimayum et al. (2020)  
at https://www.sciencedirect.com/science/article/abs/pii/S1674200119301506 
How to compile
1. place the folder in the directory "$WM_PROJECT_USER_DIR/applications/libs/ "
2. compile the model as a library 
	wmake 

3. add the library in the controlDict file of your case 
	libs(
	"libEMMSDragModel.so"
	);

4. add the particles sphericity coefficient "phis" below the type ...; in the phaseProperties dict.
	drag
	(
    	(particles in air)
   	{
       		 type            EMMS;
		 phis		0.59;
       		 residualRe      1e-3;
       		 swarmCorrection
       		 {
            		type        none;
        	}
    	}
	);

