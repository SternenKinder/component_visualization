/*
 * Ubitrack - Library for Ubiquitous Tracking
 * Copyright 2006, Technische Universitaet Muenchen, and individual
 * contributors as indicated by the @authors tag. See the
 * copyright.txt in the distribution for a full listing of individual
 * contributors.
 *
 * This is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this software; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA, or see the FSF site: http://www.fsf.org.
 */

#ifndef _ZBUFFEROUTPUT_H_
#define _ZBUFFEROUTPUT_H_

#include "RenderModule.h"
#include <utVision/Image.h>

namespace Ubitrack { namespace Drivers {


/**
 * @ingroup driver_components
 * Component for Z-Buffer output.
 * Provides a push-out port for the grey-level image.
 */
class ZBufferOutput
	: public VirtualObject
{
public:

	/**
	 * Constructor
	 * @param name edge name
	 * @param config component configuration
	 * @param componentKey the unique identifier for this component
	 * @param pModule parent object
	 */
	ZBufferOutput( const std::string& name, boost::shared_ptr< Graph::UTQLSubgraph > subgraph, 
		const VirtualObjectKey& componentKey, VirtualCamera* pModule );

	/** render the object */
	virtual void draw( Measurement::Timestamp&, int parity );

protected:

	PushSupplier< Ubitrack::Measurement::ImageMeasurement > m_port;
	boost::shared_ptr< Vision::Image > m_zBuffer;

	int m_width, m_height;
};


} } // namespace Ubitrack::Drivers

#endif

