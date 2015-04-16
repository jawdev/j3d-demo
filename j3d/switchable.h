/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /switchable.h
******************************************************************************/
#ifndef J3D_SWITCHABLE_H_
#define J3D_SWITCHABLE_H_
namespace j3d {

template<class T>
class switchable {
public:

	switchable() {
		m_is_pointer = util::is_pointer<T>::value;
		if( m_is_pointer ) m_selected = nullptr;
		else m_selected = static_cast<T>( 0 );
	}

	~switchable() { clear(); }

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
		if( select ) m_selected = m_elements[key];
		return item;
	}

	T choose( const char* key ) {
		m_selected = m_elements[key];
		return m_selected;
	}

	T active() { return m_selected; }

	T get( char* key ) {
		return m_elements[key];
	}

private:
	bool m_is_pointer;
	map<char*,T> m_elements;
	T m_selected;
};

}
#endif
