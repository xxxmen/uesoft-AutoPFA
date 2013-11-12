// PipeLineHeadList.cpp: implementation of the PipeLineHeadList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PipeLineHead.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const CString PipeLineHead::m_strKeyWordArray[] =
 {
	_T("PIPELINE-REFERENCE"),
	_T("AREA"),
	_T("BATCH"),
	_T("ATTRIBUTE0"),
	_T("ATTRIBUTE1"),
	_T("ATTRIBUTE2"),
	_T("ATTRIBUTE3"),
	_T("ATTRIBUTE4"),
	_T("ATTRIBUTE5"),
	_T("ATTRIBUTE6"),
	_T("ATTRIBUTE7"),
	_T("ATTRIBUTE8"),
	_T("ATTRIBUTE9"),
	_T("ATTRIBUTE10"),
	_T("ATTRIBUTE11"),
	_T("ATTRIBUTE12"),
	_T("ATTRIBUTE13"),
	_T("ATTRIBUTE14"),
	_T("ATTRIBUTE15"),
	_T("ATTRIBUTE16"),
	_T("ATTRIBUTE17"),
	_T("ATTRIBUTE18"),
	_T("ATTRIBUTE19"),
	_T("ATTRIBUTE20"),
	_T("ATTRIBUTE21"),
	_T("ATTRIBUTE22"),
	_T("ATTRIBUTE23"),
	_T("ATTRIBUTE24"),
	_T("ATTRIBUTE25"),
	_T("ATTRIBUTE26"),
	_T("ATTRIBUTE27"),
	_T("ATTRIBUTE28"),
	_T("ATTRIBUTE29"),
	_T("ATTRIBUTE30"),
	_T("ATTRIBUTE31"),
	_T("ATTRIBUTE32"),
	_T("ATTRIBUTE33"),
	_T("ATTRIBUTE34"),
	_T("ATTRIBUTE35"),
	_T("ATTRIBUTE36"),
	_T("ATTRIBUTE37"),
	_T("ATTRIBUTE38"),
	_T("ATTRIBUTE39"),
	_T("ATTRIBUTE40"),
	_T("ATTRIBUTE41"),
	_T("ATTRIBUTE42"),
	_T("ATTRIBUTE43"),
	_T("ATTRIBUTE44"),
	_T("ATTRIBUTE45"),
	_T("ATTRIBUTE46"),
	_T("ATTRIBUTE47"),
	_T("ATTRIBUTE48"),
	_T("ATTRIBUTE49"),
	_T("ATTRIBUTE50"),
	_T("ATTRIBUTE51"),
	_T("ATTRIBUTE52"),
	_T("ATTRIBUTE53"),
	_T("ATTRIBUTE54"),
	_T("ATTRIBUTE55"),
	_T("ATTRIBUTE56"),
	_T("ATTRIBUTE57"),
	_T("ATTRIBUTE58"),
	_T("ATTRIBUTE59"),
	_T("ATTRIBUTE60"),
	_T("ATTRIBUTE61"),
	_T("ATTRIBUTE62"),
	_T("ATTRIBUTE63"),
	_T("ATTRIBUTE64"),
	_T("ATTRIBUTE65"),
	_T("ATTRIBUTE66"),
	_T("ATTRIBUTE67"),
	_T("ATTRIBUTE68"),
	_T("ATTRIBUTE69"),
	_T("ATTRIBUTE70"),
	_T("ATTRIBUTE71"),
	_T("ATTRIBUTE72"),
	_T("ATTRIBUTE73"),
	_T("ATTRIBUTE74"),
	_T("ATTRIBUTE75"),
	_T("ATTRIBUTE76"),
	_T("ATTRIBUTE77"),
	_T("ATTRIBUTE78"),
	_T("ATTRIBUTE79"),
	_T("ATTRIBUTE80"),
	_T("ATTRIBUTE81"),
	_T("ATTRIBUTE82"),
	_T("ATTRIBUTE83"),
	_T("ATTRIBUTE84"),
	_T("ATTRIBUTE85"),
	_T("ATTRIBUTE86"),
	_T("ATTRIBUTE87"),
	_T("ATTRIBUTE88"),
	_T("ATTRIBUTE89"),
	_T("ATTRIBUTE90"),
	_T("ATTRIBUTE91"),
	_T("ATTRIBUTE92"),
	_T("ATTRIBUTE93"),
	_T("ATTRIBUTE94"),
	_T("ATTRIBUTE95"),
	_T("ATTRIBUTE96"),
	_T("ATTRIBUTE97"),
	_T("ATTRIBUTE98"),
	_T("ATTRIBUTE99"),
	_T("BEND-RADIUS"),
	_T("DATE-DMY"),
	_T("HIGHEST-PART-NUMBER"),
	_T("HIGHEST-SPOOL-NUMBER"),
	_T("HIGHEST-WELD-NUMBER"),
	_T("HIGHEST-WELD-SUPPORT-NUMBER"),
	_T("INSULATION-SPEC")
	_T("ITEM-ATTRIBUTE0"),
	_T("ITEM-ATTRIBUTE1"),
	_T("ITEM-ATTRIBUTE2"),
	_T("ITEM-ATTRIBUTE3"),
	_T("ITEM-ATTRIBUTE4"),
	_T("ITEM-ATTRIBUTE5"),
	_T("ITEM-ATTRIBUTE6"),
	_T("ITEM-ATTRIBUTE7"),
	_T("ITEM-ATTRIBUTE8"),
	_T("ITEM-ATTRIBUTE9"),
	_T("MISC-SPEC1"),
	_T("MISC-SPEC2"),
	_T("MISC-SPEC3"),
	_T("MISC-SPEC4"),
	_T("MISC-SPEC5"),
	_T("NOMINAL-CLASS"),
	_T("NOMINAL-RATING"),
	_T("OFFSET-IMPERIAL"),
	_T("OFFSET-METRIC"),
	_T("OUTPUT-FILE-NAME"),
	_T("PAINTING-SPEC"),
	_T("PIPELINE-TEMP"),
	_T("PIPELINE-TYPE"),
	_T("PIPING-SPEC"),
	_T("PROJECT-IDENTIFIER"),
	_T("REPLOT"),
	_T("REVISION"),
	_T("SPECIFIC-GRAVITY"),
	_T("SPOOL-PREFIX"),
	_T("START-CO-ORDS"),
	_T("SUPPORT-WELD-PREFIX-ERECTION"),
	_T("SUPPORT-WELD-PREFIX-FABRICATION"),
	_T("SUPPORT-WELD-PREFIX-OFFSHORE"),
	_T("TRACING-SPEC")
	_T("WELD-PREFIX-ERECTION"),
	_T("WELD-PREFIX-FABRICATION"),
	_T("WELD-PREFIX-GENRAL"),
	_T("WELD-PREFIX-OFFSHORE")	
 };


PipeLineHead::PipeLineHead()
{
     ClearAll() ;
}



BOOL PipeLineHead::IsKeyWord( const CString& strKeyWord )
{
	int nSize = sizeof( m_strKeyWordArray )/sizeof( CString ) ;
	for( int i = 0 ; i < nSize ; ++i)
	{
		if( !m_strKeyWordArray[i].CompareNoCase( strKeyWord ) )
			return TRUE ;
	}
	return FALSE ;
}
CStringArray* PipeLineHead::Find( const CString& strKey )
{
	Iterator it = m_Container.find( strKey ) ;
	if( it != m_Container.end())
		return it->second ;
	else
		return NULL ;
}

void PipeLineHead::Add( const CString& strKey , CStringArray* wordArray ) 
{
	m_Container.insert( Container::value_type( strKey, wordArray ) );
}
void PipeLineHead::Remove( const CString& strKey ) 
{
	Iterator it = m_Container.find( strKey ) ;
	if( it != m_Container.end())
	{
		delete it->second ;
		m_Container.erase( it) ;
	}

}
void PipeLineHead::ClearAll() 
{
	Iterator it = m_Container.begin() ;
	while( it != m_Container.end())
	{
		delete it->second ;
		it = m_Container.erase( it ) ;
	}	
}

int  PipeLineHead::GetSize() 
{
	return m_Container.size() ;
}

PipeLineHead::~PipeLineHead()
{

}

void PipeLineHead::Init(const CStringArray &array)
{
	int strNum = array.GetSize();
	CString wordKey;
	CStringArray *wordArray = new CStringArray;
	for (int i = 0;i < strNum;i++ )
	{
		if (IsKeyWord(array.GetAt(i)) )
		{
			wordKey = array.GetAt(i);
			wordArray->RemoveAll();
			i++;
			for(;i < strNum;i++)
			{
				if (IsKeyWord(array.GetAt(i)) )
				{
					i--;
					break;
				}
				else
				{
					wordArray->Add( array.GetAt(i) );
				}
			}
			Add(wordKey,wordArray );
		}
	}
}
