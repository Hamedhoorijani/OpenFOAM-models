modifiedJohnsonJackson with a correlation of sphericity coefficient (phis) embeded in equations.
reference : https://www.researchgate.net/publication/322722385_Assessment_of_gas-particle_flow_models_for_pseudo-2D_fluidized_bed_applications

How to compile
1. place the folder in the directory "$WM_PROJECT_USER_DIR/applications/libs/ "
2. compile the model as a library 
	wmake 

3. add the library in the controlDict file of your case 
	libs(
	"libmodifiedJohnsonJacksonFrictionalStressModel.so"
	);

4. add the sphericity coefficient "phis" and particle size in the settings of the chosen friction stress model.
        myThetaJohnsonJacksonCoeffs
        {
            Fr                      0.05;
            eta                     2;
            p                       5;
            phi                     28.5;
            alphaDeltaMin           0.05;
	    phis			0.59; //sphericity coefficient of particles
	    d                       289.0e-6;	//particle size
        }

