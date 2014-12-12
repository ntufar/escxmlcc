#ifndef AUTOFSM_ONE_STATE_HPP
#define AUTOFSM_ONE_STATE_HPP

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

class IOne_stateActionHandler;
class COne_stateFSM
{
public:
	struct data_model {
		friend class COne_stateFSM;
		data_model( void ) { /* nop */ }
	private:
		IOne_stateActionHandler* actionHandler;
	} model;

public:
	class state
	{
	public:
		virtual state* unconditional( COne_stateFSM& ) { return 0; }
		virtual state* initial( COne_stateFSM& ) { return 0; }

		template<class T> void enter( data_model&, ... ) {}
		template<class T> void exit( data_model&, ... ) {}
		virtual void exit( data_model&, const std::type_info& ) {}
		virtual ~state( void ) {}
	};

	state *cur_state;
	typedef state* ( state::*event )( COne_stateFSM& );

	template<class C> class state_actions
	{
	protected:
		void inline enter( data_model& ) { /* default enter action */ }
		void inline exit( data_model& ) { /* default exit action */ }
	};

	template<class C, class P> class composite: public P, public state_actions<C>
	{
		virtual state* initial( COne_stateFSM& ) { return 0; }
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
		state* operator()( S *s, D &d, COne_stateFSM &sc )
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
		state* operator()( S *s, D &d, COne_stateFSM &sc )
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
		S* operator()( S *s, COne_stateFSM &sc )
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
	COne_stateFSM( IOne_stateActionHandler* pActionHandler ) : cur_state( &m_scxml )
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
		state* initial( COne_stateFSM&sc ) { return transition<0, &state::initial, scxml, state_Node, internal>()( this, sc.m_state_Node, sc ); }
	} m_scxml;

	class state_Node: public composite<state_Node, scxml>
	{
	} m_state_Node;

};

class IOne_stateActionHandler
{
public:
	/* state handlers */
	virtual void stateNodeEnter( COne_stateFSM::data_model &m ) = 0;
	virtual void stateNodeExit( COne_stateFSM::data_model &m ) = 0;

	/* transition handlers */

protected:
	virtual ~IOne_stateActionHandler( void ) { /* nop */ }
};

class COne_stateActionHandlerDefault: public IOne_stateActionHandler
{
public:
	/* state handlers */
	virtual void stateNodeEnter( COne_stateFSM::data_model &m ) { /* default */ }
	virtual void stateNodeExit( COne_stateFSM::data_model &m ) { /* default */ }

	/* transition handlers */

protected:
	virtual ~COne_stateActionHandlerDefault( void ) { /* nop */ }
};


// --------------------------------------------------------------------------
template<> inline void COne_stateFSM::state_actions<COne_stateFSM::state_Node>::enter( COne_stateFSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateNodeEnter( m );
}

// --------------------------------------------------------------------------
template<> inline void COne_stateFSM::state_actions<COne_stateFSM::state_Node>::exit( COne_stateFSM::data_model &m )
// --------------------------------------------------------------------------
{
	m.actionHandler->stateNodeExit( m );
}

/* ************************************************************************ */
#endif // AUTOFSM_ONE_STATE_HPP