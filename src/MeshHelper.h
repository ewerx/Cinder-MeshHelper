/*
* Copyright (c) 2012, Ban the Rewind
* All rights reserved.
* 
* Redistribution and use in source and binary forms, with or 
* without modification, are permitted provided that the following 
* conditions are met:
* 
* Redistributions of source code must retain the above copyright 
* notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright 
* notice, this list of conditions and the following disclaimer in 
* the documentation and/or other materials provided with the 
* distribution.
* 
* Neither the name of the Ban the Rewind nor the names of its 
* contributors may be used to endorse or promote products 
* derived from this software without specific prior written 
* permission.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
* COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
*/

#pragma once

#if ! defined( CINDER_COCOA_TOUCH )
	#include "cinder/gl/Vbo.h"
#endif
#include "cinder/TriMesh.h"
#include <map>

class MeshHelper 
{
public:
	//! Create TriMesh from vectors of vertex data.
	static ci::TriMesh		createTriMesh( std::vector<uint32_t> &indices, const std::vector<ci::Vec3f> &positions,
								const std::vector<ci::Vec3f> &normals, const std::vector<ci::Vec2f> &texCoords );

	//! Create circle TriMesh with a radius of 1.0 and \a segments.
	static ci::TriMesh		createCircleTriMesh( uint32_t segments = 12 );
	/*! Create cone TriMesh with a radius and height of 1.0 and \a resolution segments. 
		Base is closed when \a closeBase is set to true. */
	static ci::TriMesh		createConeTriMesh( const ci::Vec2i &resolution = ci::Vec2i( 12, 6 ), 
		bool closeBase = true );
	//! Create cube TriMesh with an edge length of 1.0 divided into \a resolution segments.
	static ci::TriMesh		createCubeTriMesh( const ci::Vec3i &resolution = ci::Vec3i::one() );
	/*! Create cylinder TriMesh with a height of 1.0, top radius of \a topRadius, base radius 
		of \a baseRadius and \a resolution segments. Top and base are closed with \a closeTop and 
		\a closeBase flags. */
	static ci::TriMesh		createCylinderTriMesh( const ci::Vec2i &resolution = ci::Vec2i( 12, 6 ), 
		float topRadius = 1.0f, float baseRadius = 1.0f, bool closeTop = true, bool closeBase = true );
	/*! Create ring TriMesh with a radius of 1.0, \a resolution segments, and second radius 
		of \a secondRadius. */
	static ci::TriMesh		createRingTriMesh( const ci::Vec2i &resolution = ci::Vec2i( 12, 1 ), 
		float secondRadius = 0.5f );
	//! Create sphere TriMesh with a radius of 1.0 and \a resolution segments.
	static ci::TriMesh		createSphereTriMesh( const ci::Vec2i &resolution = ci::Vec2i( 12, 6 ) );
	//! Create square TriMesh with an edge length of 1.0 divided into \a resolution segments.
	static ci::TriMesh		createSquareTriMesh( const ci::Vec2i &resolution = ci::Vec2i::one() );
	/*! Create torus TriMesh with a radius of 1.0, \a segments, and second radius 
		of \a secondRadius. */
	static ci::TriMesh		createTorusTriMesh( uint32_t segments = 12, float secondRadius = 0.5f );

#if ! defined( CINDER_COCOA_TOUCH )
	//! Create VboMesh from vectors of vertex data.
	static ci::gl::VboMesh	createVboMesh( const std::vector<uint32_t> &indices, const std::vector<ci::Vec3f> &positions, 
								const std::vector<ci::Vec3f> &normals, const std::vector<ci::Vec2f> &texCoords, 
								GLenum primitiveType = GL_TRIANGLES );
	
	//! Create circle VboMesh with a radius of 1.0 and \a segments.
	static ci::gl::VboMesh	createCircleVboMesh( uint32_t segments = 12 );
	/*! Create cone VboMesh with a radius and height of 1.0 and \a resolution segments. 
		Base is closed when \a closeBase is set to true. */
	static ci::gl::VboMesh	createConeVboMesh( const ci::Vec2i &resolution = ci::Vec2i( 12, 6 ), 
		bool closeBase = true );
	//! Create cube VboMesh with an edge length of 1.0 divided into \a resolution segments.
	static ci::gl::VboMesh	createCubeVboMesh( const ci::Vec3i &resolution = ci::Vec3i::one() );
	/*! Create cylinder VboMesh with a height of 1.0, top radius of \a topRadius, base radius 
		of \a baseRadius and \a resolution segments. Top and base are closed with \a closeTop and 
		\a closeBase flags. */
	static ci::gl::VboMesh	createCylinderVboMesh( const ci::Vec2i &resolution = ci::Vec2i( 12, 6 ), 
		float topRadius = 1.0f, float baseRadius = 1.0f, bool closeTop = true, bool closeBase = true );
	/*! Create ring VboMesh with a radius of 1.0, \a resolution segments, and a second radius 
		of \a secondRadius. */
	static ci::gl::VboMesh	createRingVboMesh( const ci::Vec2i &resolution = ci::Vec2i( 12, 1 ), 
		float secondRadius = 0.5f );
	//! Create sphere VboMesh with a radius of 1.0 and \a resolution segments.
	static ci::gl::VboMesh	createSphereVboMesh( const ci::Vec2i &resolution = ci::Vec2i( 12, 6 ) );
	//! Create square VboMesh with an edge length of 1.0 divided into \a resolution segments.
	static ci::gl::VboMesh	createSquareVboMesh( const ci::Vec2i &resolution = ci::Vec2i::one() );
	/*! Create torus VboMesh with a radius of 1.0, \a segments, and second radius 
		of \a secondRadius. */
	static ci::gl::VboMesh	createTorusVboMesh( uint32_t segments = 12, float secondRadius = 0.5f );
#endif
};
