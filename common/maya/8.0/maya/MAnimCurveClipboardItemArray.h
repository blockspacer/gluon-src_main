
#ifndef _MAnimCurveClipboardItemArray
#define _MAnimCurveClipboardItemArray
//
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or distributed to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
//
// CLASS:    MAnimCurveClipboardItemArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MAnimCurveClipboardItemArray)
//
//  This class implements an array of MAnimCurveClipboardItems.  Common
// 	convenience functions are available, and the implementation is compatible
// 	with the internal Maya implementation so that it can be passed efficiently
// 	between plugins and internal maya data structures.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MAnimCurveClipboardItem.h>
#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MAnimCurveClipboardItemArray)

///  Array of MAnimCurveClipboardItem data type (OpenMayaAnim)
/**
  Implement an array of MAnimCurveClipboardItem data type.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MAnimCurveClipboardItemArray
{

public:
    ///
					MAnimCurveClipboardItemArray();
    ///
					MAnimCurveClipboardItemArray(
									const MAnimCurveClipboardItemArray& other );
    ///
					MAnimCurveClipboardItemArray(
									const MAnimCurveClipboardItem src[],
									unsigned int count );
    ///
					~MAnimCurveClipboardItemArray();
    ///
 	const MAnimCurveClipboardItem&		operator[]( unsigned int index ) const;
    ///
 	MAnimCurveClipboardItem&			operator[]( unsigned int index );
    ///
 	MStatus			set( const MAnimCurveClipboardItem& element,
						 unsigned int index );
    ///
 	unsigned int		length() const;
    ///
 	MStatus			remove( unsigned int index );
    ///
 	MStatus			insert( const MAnimCurveClipboardItem & element,
							unsigned int index );
    ///
 	MStatus			append( const MAnimCurveClipboardItem & element );
    ///
 	MStatus			clear();
    ///
	MStatus			get( MAnimCurveClipboardItem array[] ) const;
	///
	void			setSizeIncrement ( unsigned int newIncrement );
	///
	unsigned int		sizeIncrement () const;
	///
	bool			isValid( unsigned int & failedIndex ) const;

protected:
// No protected members

private:
	bool							validate( unsigned int & index,
											  unsigned int rowCount ) const;
 	MAnimCurveClipboardItemArray&	operator = (
										const MAnimCurveClipboardItemArray&)
										const;
 	MAnimCurveClipboardItemArray&	operator = (
										const MAnimCurveClipboardItemArray&);
 	void*							fArray;
	static const char*				className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MAnimCurveClipboardItemArray */
