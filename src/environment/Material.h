//
// Copyright (C) 2013 OpenSim Ltd.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#ifndef __INET_MATERIAL_H
#define __INET_MATERIAL_H

#include "INETDefs.h"
#include "Units.h"

using namespace units::values;
using namespace units::constants;

class INET_API Material
{
  public:
    static Material vacuum;
    static Material air;
    static Material copper;
    static Material aluminium;
    static Material wood;
    static Material brick;
    static Material concrete;
    static Material glass;

  protected:
    Ohmm resistivity;
    double relativePermittivity;
    double relativePermeability;

  public:
    Material(Ohmm resistivity, double relativePermittivity, double relativePermeability);

    virtual Ohmm getResistivity() const { return resistivity; }
    virtual double getRelativePermittivity() const { return relativePermittivity; }
    virtual double getRelativePermeability() const { return relativePermeability; }
    virtual double getDielectricLossTangent(Hz frequency) const;
    virtual double getRefractiveIndex() const;
    virtual mps getPropagationSpeed() const;
};

#endif // ifndef __INET_MATERIAL_H

