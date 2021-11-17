/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2019 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::dragModels::GidaspowSphe

Description
    Gidaspow model, modified in order to consider spherity of the solid particles

    Reference:
    2019. Comparing ANSYS Fluent ® and OpenFOAM ® simulations of Geldart A, B and D bubbling fluidized bed hydrodynamics

SourceFiles
    GidaspowSphe.C

\*---------------------------------------------------------------------------*/

#ifndef EMMS_H
#define EMMS_H

#include "dragModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class phasePair;

namespace dragModels
{

class ErgunEMMS;
class WenYuEMMS;

/*---------------------------------------------------------------------------*\
                           Class EMMS Declaration
\*---------------------------------------------------------------------------*/

class EMMS
:
    public dragModel
{
    // Private Data

        //- Ergun EMMS drag model
        autoPtr<ErgunEMMS> ErgunEMMS_;

        //- Wen Yu EMMS drag model
        autoPtr<WenYuEMMS> WenYuEMMS_;


public:

    //- Runtime type information
    TypeName("EMMS");


    // Constructors

        //- Construct from a dictionary and an ordered phase pair
        EMMS
        (
            const dictionary& interfaceDict,
            const phasePair& pair,
            const bool registerObject
        );


    //- Destructor
    virtual ~EMMS();


    // Member Functions

        //- Drag coefficient
        virtual tmp<volScalarField> CdRe() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace dragModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
