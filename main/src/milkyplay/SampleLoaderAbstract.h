/*
 * Copyright (c) 2009, The MilkyTracker Team.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name of the <ORGANIZATION> nor the names of its contributors
 *   may be used to endorse or promote products derived from this software
 *   without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  SampleLoaderAbstract.h
 *  MilkyPlay
 *
 *  Created by Peter Barth on 14.09.05.
 *
 */

#ifndef SAMPLELOADERABSTRACT__H
#define SAMPLELOADERABSTRACT__H

#include "XMFile.h"

class XModule;
struct TXMSample;

class SampleLoaderAbstract
{
private:
	 static const char* emptyChannelName;
	
protected:
	XModule& theModule;
	const SYSCHAR* theFileName;
	const char* preferredDefaultName;
	
	void nameToSample(const char* name, TXMSample* smp); 
	
public:
	SampleLoaderAbstract(const SYSCHAR* fileName, XModule& module);

	virtual ~SampleLoaderAbstract() {}

	virtual bool identifySample() = 0;
	
	virtual mp_sint32 getNumChannels() { return 1; }
	
	virtual const char* getChannelName(mp_sint32 channelIndex) { return emptyChannelName; }

	virtual mp_sint32 loadSample(mp_sint32 index, mp_sint32 channelIndex) = 0;

	virtual mp_sint32 saveSample(const SYSCHAR* fileName, mp_sint32) { return 0; }
	
	void setPreferredDefaultName(const char* preferredDefaultName) { this->preferredDefaultName = preferredDefaultName; }
};

#endif

