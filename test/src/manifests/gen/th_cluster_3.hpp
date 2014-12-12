#ifndef AUTOFSM_TH_CLUSTER_3_HPP
#define AUTOFSM_TH_CLUSTER_3_HPP

/*
 *                                     escxmlcc product
 *                                           fsm
 *
 * @ingroup Autogenerated::FSM
 * @author  escxmlcc
 * 
 * @brief   This program was generated by escxmlcc fsm compiler written by Yuriy Gurin. This is
 *          an extended version of original scxmlcc compiler written by Jan Pedersen. For more
 *          information see project website http://escxmlcc.sourceforge.net
 */

// --------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------

#include <typeinfo>
#include <memory>

// --------------------------------------------------------------------------
// User space
// --------------------------------------------------------------------------

/* no user data */

// --------------------------------------------------------------------------
// Code definition
// --------------------------------------------------------------------------

class ITh_cluster_3ActionHandler;
class CTh_cluster_3FSM
{
public:
	struct data_model {
		friend class CTh_cluster_3FSM;
		data_model( void ): a() { /* nop */ }
		int a;
	private:
		ITh_cluster_3ActionHandler* actionHandler;
	} model;

public:
	// --------------------------------------------------------------------------
	void setA( const int& value )
	// --------------------------------------------------------------------------
	{
		model.a = value;
	}

public:
	class state
	{
	public:
		virtual state* event_w( CTh_cluster_3FSM& ) { return 0; }
		virtual state* unconditional( CTh_cluster_3FSM& ) { return 0; }
		virtual state* initial( CTh_cluster_3FSM& ) { return 0; }

		template<class T> void enter( data_model&, ... ) {}
		template<class T> void exit( data_model&, ... ) {}
		virtual void exit( data_model&, const std::type_info& ) {}
		virtual ~state( void ) {}
	};

	state *cur_state;
	typedef state* ( state::*event )( CTh_cluster_3FSM& );

	template<class C> class state_actions
	{
	protected:
		void inline enter( data_model& ) { /* default enter action */ }
		void inline exit( data_model& ) { /* default exit action */ }
	};

	template<class C, class P> class composite: public P, public state_actions<C>
	{
		virtual state* initial( CTh_cluster_3FSM& ) { return 0; }
	public:
		// LCA calculation
		template<class T> void enter( data_model&, composite* ) {}
		template<class T> void enter( data_model &m, ... ) { P::template enter<T>( m, (T*)0 ); state_actions<C>::enter( m ); }
		template<class T> void exit( data_model&, composite* ) {}
		template<class T> void exit( data_model &m, ... ) { state_actions<C>::exit( m ); P::template exit<T>( m, (T*)0 ); }
		virtual void exit( data_model &m, const std::type_info &sti ) { if ( typeid(C) == sti ) return; state_actions<C>::exit( m ); P::exit( m, sti ); }
	};

	class no_state { /* dup */ };
	enum transition_type { external, internal };

	template<int index, event E, class S, class D0 = no_state> class transition_actions
	{
	protected:
		void enter(data_model&) { /* default enter action */ }
		bool condition(data_model&) { return true; } /* default condition action */
	};

	// external transition
	template<int index, event E, class S, class D = no_state, transition_type T = external> class transition: public transition_actions<index, E, S, D>
	{
	public:
		state* operator()( S *s, D &d, CTh_cluster_3FSM &sc )
		{
			if( !transition_actions<index, E, S, D>::condition(sc.model) ) return 0;
			s->exit( sc.model, typeid(S) );
			s->template exit<D>( sc.model );
			transition_actions<index, E, S, D>::enter( sc.model );
			d.template enter<S>( sc.model );
			return &d;
		}
	};

	// internal transition
	template<int index, event E, class S, class D> class transition<index, E, S, D, internal>: public transition_actions<index, E, S, D>
	{
	public:
		state* operator()( S *s, D &d, CTh_cluster_3FSM &sc )
		{
			if ( !transition_actions<index, E, S, D>::condition(sc.model) ) return 0;
			s->exit( sc.model, typeid(S) );
			s->template exit<D>( sc.model, (D*)0 );
			transition_actions<index, E, S, D>::enter( sc.model );
			d.template enter<S>( sc.model, (S*)0 );
			return &d;
		}
	};

	// transition with no target
	template<int index, event E, class S> class transition<index, E, S, no_state>: public transition_actions<index, E, S, no_state>
	{
	public:
		S* operator()( S *s, CTh_cluster_3FSM &sc )
		{
			if ( !transition_actions<index, E, S, no_state>::condition(sc.model) ) return 0;
			transition_actions<index, E, S, no_state>::enter( sc.model );
			return s;
		}
	};

private:
	// --------------------------------------------------------------------------
	bool dispatch_event( event e )
	// --------------------------------------------------------------------------
	{
		state *next_state;
		if ( (next_state = (cur_state->*e)(*this)) ) cur_state = next_state;
		return next_state;
	}

public:
	// --------------------------------------------------------------------------
	void dispatch( event e )
	// --------------------------------------------------------------------------
	{
		bool cont = dispatch_event( e );
		while ( cont ) {
			if ( (cont = dispatch_event(&state::initial)) );
			else if ( (cont = dispatch_event(&state::unconditional)) );
			else break;
		}
	}

	// --------------------------------------------------------------------------
	CTh_cluster_3FSM( ITh_cluster_3ActionHandler* pActionHandler ) : cur_state( &m_scxml )
	// --------------------------------------------------------------------------
	{
		model.actionHandler = pActionHandler;
	}

	// --------------------------------------------------------------------------
	void init( void )
	// --------------------------------------------------------------------------
	{
		dispatch( &state::initial );
	}

	class scxml : public composite<scxml, state>
	{
		state* initial( CTh_cluster_3FSM&sc ) { return transition<0, &state::initial, scxml, state_init, internal>()( this, sc.m_state_init, sc ); }
	} m_scxml;

	class state_init: public composite<state_init, scxml>
	{
		virtual state* unconditional( CTh_cluster_3FSM &sc ) {
			int& a = sc.model.a;
			if ( true ) return transition<1, &state::unconditional, state_init, state_Cluster>()( this, sc.m_state_Cluster, sc );
			else return 0;
		}
	} m_state_init;

	class state_Cluster: public composite<state_Cluster, scxml>
	{
		state* initial( CTh_cluster_3FSM &sc ) { return transition<0, &state::initial, state_Cluster, state_i, internal>()( this, sc.m_state_i, sc ); }
		virtual state* unconditional( CTh_cluster_3FSM &sc ) {
			int& a = sc.model.a;
			if ( a == 0 ) return transition<2, &state::unconditional, state_Cluster, state_B>()( this, sc.m_state_B, sc );
			else return 0;
		}
	} m_state_Cluster;

	class state_i: public composite<state_i, state_Cluster>
	{
		virtual state* unconditional( CTh_cluster_3FSM &sc ) {
			int& a = sc.model.a;
			if ( true ) return transition<3, &state::unconditional, state_i, state_A>()( this, sc.m_state_A, sc );
			else return 0;
		}
	} m_state_i;

	class state_A: public composite<state_A, state_Cluster>
	{
	} m_state_A;

	class state_B: public composite<state_B, scxml>
	{
		virtual state* unconditional( CTh_cluster_3FSM &sc ) {
			int& a = sc.model.a;
			if ( ++a < 3 ) return transition<4, &state::unconditional, state_B, state_B>()( this, sc.m_state_B, sc );
			if ( a == 3 ) return transition<5, &state::unconditional, state_B, state_C>()( this, sc.m_state_C, sc );
			else return 0;
		}
	} m_state_B;

	class state_C: public composite<state_C, scxml>
	{
		state* event_w( CTh_cluster_3FSM &sc ) {
			int& a = sc.model.a;
			if ( a > 2 ) return transition<6, &state::event_w, state_C, state_D>()( this, sc.m_state_D, sc );
			else return 0;
		}
		virtual state* unconditional( CTh_cluster_3FSM &sc ) { return 0; }
	} m_state_C;

	class state_D: public composite<state_D, scxml>
	{
	} m_state_D;

};

class ITh_cluster_3ActionHandler
{
public:
	/* state handlers */
	virtual void stateInitEnter( CTh_cluster_3FSM::data_model &m ) = 0;
	virtual void stateInitExit( CTh_cluster_3FSM::data_model &m ) = 0;
	virtual void stateClusterEnter( CTh_cluster_3FSM::data_model &m ) = 0;
	virtual void stateClusterExit( CTh_cluster_3FSM::data_model &m ) = 0;
	virtual void stateIEnter( CTh_cluster_3FSM::data_model &m ) = 0;
	virtual void stateIExit( CTh_cluster_3FSM::data_model &m ) = 0;
	virtual void stateAEnter( CTh_cluster_3FSM::data_model &m ) = 0;
	virtual void stateAExit( CTh_cluster_3FSM::data_model &m ) = 0;
	virtual void stateBEnter( CTh_cluster_3FSM::data_model &m ) = 0;
	virtual void stateBExit( CTh_cluster_3FSM::data_model &m ) = 0;
	virtual void stateCEnter( CTh_cluster_3FSM::data_model &m ) = 0;
	virtual void stateCExit( CTh_cluster_3FSM::data_model &m ) = 0;
	virtual void stateDEnter( CTh_cluster_3FSM::data_model &m ) = 0;
	virtual void stateDExit( CTh_cluster_3FSM::data_model &m ) = 0;

	/* transition handlers */
	virtual void onFoo( CTh_cluster_3FSM::data_model& m ) = 0;
	virtual void onBar( CTh_cluster_3FSM::data_model& m ) = 0;
	virtual void onGap( CTh_cluster_3FSM::data_model& m ) = 0;
	virtual void onSub( CTh_cluster_3FSM::data_model& m, int value ) = 0;

protected:
	virtual ~ITh_cluster_3ActionHandler( void ) { /* nop */ }
};

class CTh_cluster_3ActionHandlerDefault: public ITh_cluster_3ActionHandler
{
public:
	/* state handlers */
	virtual void stateInitEnter( CTh_cluster_3FSM::data_model &m ) { /* default */ }
	virtual void stateInitExit( CTh_cluster_3FSM::data_model &m ) { /* default */ }
	virtual void stateClusterEnter( CTh_cluster_3FSM::data_model &m ) { /* default */ }
	virtual void stateClusterExit( CTh_cluster_3FSM::data_model &m ) { /* default */ }
	virtual void stateIEnter( CTh_cluster_3FSM::data_model &m ) { /* default */ }
	virtual void stateIExit( CTh_cluster_3FSM::data_model &m ) { /* default */ }
	virtual void stateAEnter( CTh_cluster_3FSM::data_model &m ) { /* default */ }
	virtual void stateAExit( CTh_cluster_3FSM::data_model &m ) { /* default */ }
	virtual void stateBEnter( CTh_cluster_3FSM::data_model &m ) { /* default */ }
	virtual void stateBExit( CTh_cluster_3FSM::data_model &m ) { /* default */ }
	virtual void stateCEnter( CTh_cluster_3FSM::data_model &m ) { /* default */ }
	virtual void stateCExit( CTh_cluster_3FSM::data_model &m ) { /* default */ }
	virtual void stateDEnter( CTh_cluster_3FSM::data_model &m ) { /* default */ }
	virtual void stateDExit( CTh_cluster_3FSM::data_model &m ) { /* default */ }

	/* transition handlers */
	virtual void onFoo( CTh_cluster_3FSM::data_model& m ) { /* default */ }
	virtual void onBar( CTh_cluster_3FSM::data_model& m ) { /* default */ }
	virtual void onGap( CTh_cluster_3FSM::data_model& m ) { /* default */ }
	virtual void onSub( CTh_cluster_3FSM::data_model& m, int value ) { /* default */ }

protected:
	virtual ~CTh_cluster_3ActionHandlerDefault( void ) { /* nop */ }
};


// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::state_actions<CTh_cluster_3FSM::state_init>::enter( CTh_cluster_3FSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateInitEnter( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::state_actions<CTh_cluster_3FSM::state_init>::exit( CTh_cluster_3FSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateInitExit( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::state_actions<CTh_cluster_3FSM::state_Cluster>::enter( CTh_cluster_3FSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateClusterEnter( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::state_actions<CTh_cluster_3FSM::state_Cluster>::exit( CTh_cluster_3FSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateClusterExit( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::transition_actions<2, &CTh_cluster_3FSM::state::unconditional, CTh_cluster_3FSM::state_Cluster, CTh_cluster_3FSM::state_B>::enter(CTh_cluster_3FSM::data_model& m )
// --------------------------------------------------------------------------
{
	m.actionHandler->onBar( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::state_actions<CTh_cluster_3FSM::state_i>::enter( CTh_cluster_3FSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateIEnter( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::state_actions<CTh_cluster_3FSM::state_i>::exit( CTh_cluster_3FSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateIExit( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::transition_actions<3, &CTh_cluster_3FSM::state::unconditional, CTh_cluster_3FSM::state_i, CTh_cluster_3FSM::state_A>::enter(CTh_cluster_3FSM::data_model& m )
// --------------------------------------------------------------------------
{
	m.actionHandler->onFoo( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::state_actions<CTh_cluster_3FSM::state_A>::enter( CTh_cluster_3FSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateAEnter( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::state_actions<CTh_cluster_3FSM::state_A>::exit( CTh_cluster_3FSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateAExit( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::state_actions<CTh_cluster_3FSM::state_B>::enter( CTh_cluster_3FSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateBEnter( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::state_actions<CTh_cluster_3FSM::state_B>::exit( CTh_cluster_3FSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateBExit( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::transition_actions<4, &CTh_cluster_3FSM::state::unconditional, CTh_cluster_3FSM::state_B, CTh_cluster_3FSM::state_B>::enter(CTh_cluster_3FSM::data_model& m )
// --------------------------------------------------------------------------
{
	m.actionHandler->onGap( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::transition_actions<5, &CTh_cluster_3FSM::state::unconditional, CTh_cluster_3FSM::state_B, CTh_cluster_3FSM::state_C>::enter(CTh_cluster_3FSM::data_model& m )
// --------------------------------------------------------------------------
{
	m.actionHandler->onSub( m, m.a );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::state_actions<CTh_cluster_3FSM::state_C>::enter( CTh_cluster_3FSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateCEnter( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::state_actions<CTh_cluster_3FSM::state_C>::exit( CTh_cluster_3FSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateCExit( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::transition_actions<6, &CTh_cluster_3FSM::state::event_w, CTh_cluster_3FSM::state_C, CTh_cluster_3FSM::state_D>::enter(CTh_cluster_3FSM::data_model& m )
// --------------------------------------------------------------------------
{
	m.actionHandler->onGap( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::state_actions<CTh_cluster_3FSM::state_D>::enter( CTh_cluster_3FSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateDEnter( m );
}

// --------------------------------------------------------------------------
template<> inline void CTh_cluster_3FSM::state_actions<CTh_cluster_3FSM::state_D>::exit( CTh_cluster_3FSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateDExit( m );
}

/* ************************************************************************ */
#endif // AUTOFSM_TH_CLUSTER_3_HPP