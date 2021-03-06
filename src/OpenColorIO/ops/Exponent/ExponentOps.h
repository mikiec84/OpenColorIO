/*
Copyright (c) 2003-2010 Sony Pictures Imageworks Inc., et al.
All Rights Reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:
* Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
* Neither the name of Sony Pictures Imageworks nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef INCLUDED_OCIO_EXPONENTOP_H
#define INCLUDED_OCIO_EXPONENTOP_H

#include <OpenColorIO/OpenColorIO.h>

#include "Op.h"

#include <vector>

OCIO_NAMESPACE_ENTER
{
    class ExponentOpData;
    typedef OCIO_SHARED_PTR<ExponentOpData> ExponentOpDataRcPtr;
    typedef OCIO_SHARED_PTR<const ExponentOpData> ConstExponentOpDataRcPtr;

    class ExponentOpData : public OpData
    {
    public:
        ExponentOpData();
        ExponentOpData(const double * exp4);
        virtual ~ExponentOpData() {}

        ExponentOpData & operator = (const ExponentOpData & rhs);

        virtual Type getType() const override { return ExponentType; }

        virtual bool isNoOp() const override;
        virtual bool isIdentity() const override;

        virtual bool hasChannelCrosstalk() const override { return false; }

        double m_exp4[4];

        virtual void finalize() override;
    };

    // If the exponent is 1.0, this will return without clamping
    // Otherwise, will be clamped between [0.0, inf]
    
    void CreateExponentOp(OpRcPtrVec & ops,
                          const double(&vec4)[4],
                          TransformDirection direction);
}
OCIO_NAMESPACE_EXIT

#endif
