/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /labler.h
******************************************************************************/
#ifndef J3D_LABLER_H_
#define J3D_LABLER_H_
namespace j3d {

template<class T>
class labler {
public:

	labler() {
		m_is_pointer = util::is_pointer<T>::value;
		m_zero = static_cast<T>( 0 );
		if( m_is_pointer ) m_selected = nullptr;
		else m_selected = m_zero;
	}

	~labler() { clear(); }

	void clear( bool destroy = true ) {
		if( m_is_pointer && destroy ) {
			for( auto iter = m_elements.begin(); iter != m_elements.end(); iter++ ) {
				SAFE_DELETE( iter->second );
			}
		}
		m_elements.clear();
	}

	bool empty() { return m_elements.empty(); }

	T add( char* key, T const &item, bool select = false ) {
		m_elements.insert( pair<char*,T>( key, item ) );
		if( select ) m_selected = item;
		return item;
	}

	bool has( char* key ) {
		try { m_elements.at( key ); }
		catch( ... ) { return false; }
		return true;
	}

	bool hasActive() {
		if( m_is_pointer ) return ( m_selected != nullptr );
		else return ( m_selected != m_zero );
	}

	T find( char* key, bool select = false ) {
		if( !has( key ) ) {
			if( m_is_pointer ) return nullptr;
			else return m_zero;
		}
		if( select ) m_selected = m_elements[key];
		return m_elements[key];
	}

	T active() { return m_selected; }

	bool select( char* key ) {
		if( !has( key ) ) return false;
		m_selected = m_elements[key];
		return true;
	}

private:
	bool m_is_pointer;
	map<char*,T> m_elements;
	T m_selected;
	T m_zero;
};

}
#endif

