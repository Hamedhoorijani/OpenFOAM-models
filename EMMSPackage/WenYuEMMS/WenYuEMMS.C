/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2018 OpenFOAM Foundation
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

\*---------------------------------------------------------------------------*/

#include "WenYuEMMS.H"
#include "phasePair.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace dragModels
{
    defineTypeNameAndDebug(WenYuEMMS, 0);
    addToRunTimeSelectionTable(dragModel, WenYuEMMS, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::dragModels::WenYuEMMS::WenYuEMMS
(
    const dictionary& dict,
    const phasePair& pair,
    const bool registerObject
)
:
    dragModel(dict, pair, registerObject),
    residualRe_("residualRe", dimless, dict),
    
    phis_("phis", dimless, dict)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::dragModels::WenYuEMMS::~WenYuEMMS()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField> Foam::dragModels::WenYuEMMS::CdRe() const
{
    volScalarField alpha2
    (
        max(scalar(1) - pair_.dispersed(), pair_.continuous().residualAlpha())
    );

    volScalarField Res(alpha2*pair_.Re());
    volScalarField CdsRes
    (
        neg(Res - 1000)*24.0/(phis_)*(1.0 + 0.15*pow(Res, 0.687))
      + pos0(Res - 1000)*0.44/(phis_)*max(Res, residualRe_)
    );

    return
        3/4* CdsRes
       *pow(alpha2, -3.65)
       *max(pair_.continuous(), pair_.continuous().residualAlpha())
       * (
            pos0(phis_-0.74)*neg(phis_-0.82)*(-0.576 + 0.0214/(4*pow((phis_ -0.7463),2)+0.0044))
            +  pos0(phis_-0.82)*neg(phis_-0.97)*(-0.0101 + 0.0038/(4*pow((phis_ -0.7789),2)+0.004))
            +pos0(phis_-0.97)*(-31.8295 +32.8295* phis_)
            );
}


// ************************************************************************* //
