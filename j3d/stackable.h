/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /stackable.h
******************************************************************************/
#ifndef J3D_STACKABLE_H_
#define J3D_STACKABLE_H_
namespace j3d {


template<class T>
class stackable {
public:

	stackable() { m_is_pointer = util::is_pointer<T>::value; }

	~stackable() { clear(); }

	void clear( bool destroy = true ) {
		if( m_is_pointer && destroy ) {
			for( unsigned int i = 0; i < m_elements.size(); i++ ) {
				SAFE_DELETE( m_elements[i] );
			}
		}
		m_elements.clear();
	}

	bool empty() { return m_elements.empty(); }

	T push( T const &item ) {
		m_elements.push_back( item );
		return item;
	}

	T pop( bool destroy = true ) {
		if( m_elements.empty() ) {
			if( m_is_pointer ) return nullptr;
			else return static_cast<T>( 0 );
		}
		T last_el = top();
		m_elements.pop_back();
		if( m_is_pointer && destroy ) {
			SAFE_DELETE( last_el );
			return nullptr;
		}
		return last_el;
	}

	T top() {
		if( m_elements.empty() ) {
			if( m_is_pointer ) return nullptr;
			else return static_cast<T>( 0 );
		} else return m_elements[m_elements.size()-1];
	}

private:
	bool m_is_pointer;
	vector<T> m_elements;
};

}
#endif
