/*************************************************************************
 ** Copyright (C) 2013 Jan Pedersen <jp@jp-embedded.com>
 ** 
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 ** 
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 ** 
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *************************************************************************/

#ifndef __CPP_OUTPUT
#define __CPP_OUTPUT

//todo store scxml in internal format. to be able to parse other input formats
#include "scxml_parser.h"
#include "options.h"

#include <ostream>

class cpp_output {

	std::ostream &out;
   std::ostream &out_cpp;
	const scxml_parser &sc;
	const options &opt;
	std::string tab;
   int mTransitionIndex;

	public:
	cpp_output(std::ostream &ofs, std::ostream& ofscpp,/*std::ostream &ofs_aha, std::ostream &ofs_ahd,*/ const scxml_parser &sc, const options &op) : out(ofs), out_cpp(ofscpp),/* out_aha(ofs_aha), out_ahd(ofs_ahd),*/ sc(sc), opt(op), tab("\t"), mTransitionIndex(0) {};

	void gen();

	protected:
	std::string classname();
   std::string getActionHandlerName();
   std::string getActionHandlerDefaultName();
	std::string state_t();
	std::string state_actions_t();
	std::string state_composite_t();
	std::string state_parallel_t();
	void gen_model_base();
	void gen_state_base();
	void gen_state_composite_base();
	void gen_state_parallel_base();
	void gen_state_actions_base();
	void gen_transition_base();
	void gen_state(const scxml_parser::state &state);
	void gen_sc();
	void trim();

	private:
	scxml_parser::state_list children(const scxml_parser::state &state);
   void gen_ahi_header();
   void gen_ahd_header();
   void gen_cpp();
   void gen_template_calls();

   std::string UpperFirstLetter(std::string word);
   
};

#endif

