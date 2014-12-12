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

#ifndef __SC_INCLUDE_1
#define __SC_INCLUDE_1

#include <typeinfo>
#include <queue>
#include <memory>
#include <vector>

class sc_include_1
{
private:
	struct data_model {
		data_model( void ): v() { /* nop */ }
		std::vector<int> v;
	} model;

public:
	// --------------------------------------------------------------------------
	void setV( const std::vector<int>& value )
	// --------------------------------------------------------------------------
	{
		model.v = value;
	}

public:
	class state
	{
	public:
		virtual state* event_q(sc_include_1&) { return 0; }
		virtual state* unconditional(sc_include_1&) { return 0; }
		virtual state* initial(sc_include_1&) { return 0; }

		template<class T> void enter(data_model&, ...) {}
		template<class T> void exit(data_model&, ...) {}
		virtual void exit(data_model&, const std::type_info&) {}
		virtual ~state() {}
	};

	state *cur_state;
	typedef state* (state::*event)(sc_include_1&);

	template<class C> class state_actions
	{
	protected:
		void enter(data_model&) {} // default enter action
		void exit(data_model&) {} // default exit action
	};

	template<class C, class P> class composite : public P, public state_actions<C>
	{
		virtual state* initial(sc_include_1&) { return 0; }
	public:
		// LCA calculation
		template<class T> void enter(data_model&, composite*) {}
		template<class T> void enter(data_model &m, ...) { P::template enter<T>(m, (T*)0); state_actions<C>::enter(m); }
		template<class T> void exit(data_model&, composite*) {}
		template<class T> void exit(data_model &m, ...) { state_actions<C>::exit(m); P::template exit<T>(m, (T*)0); }
		virtual void exit(data_model &m, const std::type_info &sti) { if(typeid(C) == sti) return; state_actions<C>::exit(m); P::exit(m, sti); }
	};

	class no_state {};
	enum transition_type { external, internal };

	template<event E, class S, class D0 = no_state> class transition_actions
	{
	protected:
		void enter(data_model&) {} // default enter action
		bool condition(data_model&) { return true; } // default condition action
	};

	// external transition
	template<event E, class S, class D = no_state, transition_type T = external> class transition : public transition_actions<E, S, D>
	{
	public:
		state* operator ()(S *s, D &d, sc_include_1 &sc)
		{
			if(!transition_actions<E, S, D>::condition(sc.model)) return 0;
			s->exit(sc.model, typeid(S));
			s->template exit<D>(sc.model);
			transition_actions<E, S, D>::enter(sc.model);
			d.template enter<S>(sc.model);
			return &d;
		}
	};

	// internal transition
	template<event E, class S, class D> class transition<E, S, D, internal> : public transition_actions<E, S, D>
	{
	public:
		state* operator ()(S *s, D &d, sc_include_1 &sc)
		{
			if(!transition_actions<E, S, D>::condition(sc.model)) return 0;
			s->exit(sc.model, typeid(S));
			s->template exit<D>(sc.model, (D*)0);
			transition_actions<E, S, D>::enter(sc.model);
			d.template enter<S>(sc.model, (S*)0);
			return &d;
		}
	};

	// transition with no target
	template<event E, class S> class transition<E, S, no_state> : public transition_actions<E, S, no_state>
	{
	public:
		S* operator ()(S *s, sc_include_1 &sc)
		{
			if(!transition_actions<E, S, no_state>::condition(sc.model)) return 0;
			transition_actions<E, S, no_state>::enter(sc.model);
			return s;
		}
	};

private:
	// --------------------------------------------------------------------------
	bool dispatch_event(event e)
	// --------------------------------------------------------------------------
	{
		state *next_state;
		if ((next_state = (cur_state->*e)(*this))) cur_state = next_state;
		return next_state;
	}

public:
	// --------------------------------------------------------------------------
	void dispatch(event e)
	// --------------------------------------------------------------------------
	{
		bool cont = dispatch_event(e);
		while ( cont ) {
			if ((cont = dispatch_event(&state::initial)));
			else if ((cont = dispatch_event( &state::unconditional )));
			else break;
		}
	}

	// --------------------------------------------------------------------------
	sc_include_1() : cur_state( &m_scxml )
	// --------------------------------------------------------------------------
	{
	}

	// --------------------------------------------------------------------------
	void init( void )
	// --------------------------------------------------------------------------
	{
		dispatch( &state::initial );
	}

	class scxml : public composite<scxml, state>
	{
		state* initial(sc_include_1&sc) { return transition<&state::initial, scxml, state_init, internal>()(this, sc.m_state_init, sc); }
	} m_scxml;

	class state_init : public composite<state_init, scxml>
	{
		state* event_q(sc_include_1 &sc) {
			std::vector<int>& v = sc.model.v;
			if ( v.size() > 0 ) return transition<&state::event_q, state_init, state_full>()(this, sc.m_state_full, sc);
			if ( v.size() == 0 ) return transition<&state::event_q, state_init, state_empty>()(this, sc.m_state_empty, sc);
			else return 0;
		}
		virtual state* unconditional(sc_include_1 &sc) { return 0; }
	} m_state_init;

	class state_full : public composite<state_full, scxml>
	{
	} m_state_full;

	class state_empty : public composite<state_empty, scxml>
	{
	} m_state_empty;

};

#endif
