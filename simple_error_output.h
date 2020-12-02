/*******************************************************************************
*                                                                              * 
*                Copyright 2020 Makoto World - Talles HBF                      *
*                                                                              *
*        Licensed under the Apache License, Version 2.0 (the "License");       *
*       you may not use this file  except in compliance with the License.      *
*                 You may obtain a copy of the License at                      *
*                                                                              *
*               http://www.apache.org/licenses/LICENSE-2.0                     *
*                                                                              *
*     Unless required by applicable law or  agreed to in writing, software     *
*       distributed under the License is distributed on an "AS IS" BASIS,      *
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
*     See the License for the specific language governing permissions  and     *
*                      limitations under the License.                          *
*                                                                              *
*******************************************************************************/ 
/*******************************************************************************
*  Author: Talles HBF - Kourei                                                 *
*  Collab: <empty>                                                             *
*******************************************************************************/


#ifndef MK_VERBOSE_LIB_SIMPLE_ERROR_OUTPUT_H_
#define MK_VERBOSE_LIB_SIMPLE_ERROR_OUTPUT_H_

  #if defined(_MK_SIMPLE_ERROR_) // Precompiler for active error verbose messege.
    #ifdef __cplusplus     // G++ or CLang++ Compilers  - C++.
      #define mk_serror(x) \
        if((strncmp(mk_verbose_line,__FILE__, _MAX_VERBOSE_SIZE_) != 0))       \
          {                                                                    \
          strncpy(mk_verbose_line, __FILE__, _MAX_VERBOSE_SIZE_);              \
          std::cerr << _B_YLW_ << "::" << __FILE__ << _RESET_ << endl;         \
          }                                                                    \
        mk_error_count += 1;                                                   \
        cerr << _B_RED_ << "\t<" << __LINE__ << "> " << _RESET_ << x << endl; 
    #else                // GCC ou CLang Compilers.    - C [[Default]]
      #define mk_serror(x)                                                     \
        if((strncmp(mk_verbose_line,__FILE__, _MAX_VERBOSE_SIZE_) != 0))       \
          {                                                                    \
          strncpy(mk_verbose_line, __FILE__, _MAX_VERBOSE_SIZE_);              \
          fprintf                                                              \
            (                                                                  \
            stderr,                                                            \
            "%s::%s::  %s\n",                                                  \
            _B_YLW_, __FILE__, _RESET_                                         \
            );                                                                 \
          }                                                                    \
        mk_error_count += 1;                                                   \
        fprintf                                                                \
          (                                                                    \
          stderr,                                                              \
          "%s\t<%d>%s %s \n",                                                  \
          _B_RED_,__LINE__,_RESET_ , x                                         \
          )
    #endif // END _L_CPP.
  // If not has been defined V_simple, all function will be set blank.
  #else
    #define mk_serror(x)
  #endif // END _V_S_ERROR_.

#endif // MK_VERBOSE_LIB_HEADER_
