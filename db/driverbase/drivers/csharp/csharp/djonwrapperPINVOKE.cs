/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.9
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace djondb {

using System;
using System.Runtime.InteropServices;

class djonwrapperPINVOKE {

  protected class SWIGExceptionHelper {

    public delegate void ExceptionDelegate(string message);
    public delegate void ExceptionArgumentDelegate(string message, string paramName);

    static ExceptionDelegate applicationDelegate = new ExceptionDelegate(SetPendingApplicationException);
    static ExceptionDelegate arithmeticDelegate = new ExceptionDelegate(SetPendingArithmeticException);
    static ExceptionDelegate divideByZeroDelegate = new ExceptionDelegate(SetPendingDivideByZeroException);
    static ExceptionDelegate indexOutOfRangeDelegate = new ExceptionDelegate(SetPendingIndexOutOfRangeException);
    static ExceptionDelegate invalidCastDelegate = new ExceptionDelegate(SetPendingInvalidCastException);
    static ExceptionDelegate invalidOperationDelegate = new ExceptionDelegate(SetPendingInvalidOperationException);
    static ExceptionDelegate ioDelegate = new ExceptionDelegate(SetPendingIOException);
    static ExceptionDelegate nullReferenceDelegate = new ExceptionDelegate(SetPendingNullReferenceException);
    static ExceptionDelegate outOfMemoryDelegate = new ExceptionDelegate(SetPendingOutOfMemoryException);
    static ExceptionDelegate overflowDelegate = new ExceptionDelegate(SetPendingOverflowException);
    static ExceptionDelegate systemDelegate = new ExceptionDelegate(SetPendingSystemException);

    static ExceptionArgumentDelegate argumentDelegate = new ExceptionArgumentDelegate(SetPendingArgumentException);
    static ExceptionArgumentDelegate argumentNullDelegate = new ExceptionArgumentDelegate(SetPendingArgumentNullException);
    static ExceptionArgumentDelegate argumentOutOfRangeDelegate = new ExceptionArgumentDelegate(SetPendingArgumentOutOfRangeException);

    [DllImport("djonwrapper", EntryPoint="SWIGRegisterExceptionCallbacks_djonwrapper")]
    public static extern void SWIGRegisterExceptionCallbacks_djonwrapper(
                                ExceptionDelegate applicationDelegate,
                                ExceptionDelegate arithmeticDelegate,
                                ExceptionDelegate divideByZeroDelegate, 
                                ExceptionDelegate indexOutOfRangeDelegate, 
                                ExceptionDelegate invalidCastDelegate,
                                ExceptionDelegate invalidOperationDelegate,
                                ExceptionDelegate ioDelegate,
                                ExceptionDelegate nullReferenceDelegate,
                                ExceptionDelegate outOfMemoryDelegate, 
                                ExceptionDelegate overflowDelegate, 
                                ExceptionDelegate systemExceptionDelegate);

    [DllImport("djonwrapper", EntryPoint="SWIGRegisterExceptionArgumentCallbacks_djonwrapper")]
    public static extern void SWIGRegisterExceptionCallbacksArgument_djonwrapper(
                                ExceptionArgumentDelegate argumentDelegate,
                                ExceptionArgumentDelegate argumentNullDelegate,
                                ExceptionArgumentDelegate argumentOutOfRangeDelegate);

    static void SetPendingApplicationException(string message) {
      SWIGPendingException.Set(new System.ApplicationException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingArithmeticException(string message) {
      SWIGPendingException.Set(new System.ArithmeticException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingDivideByZeroException(string message) {
      SWIGPendingException.Set(new System.DivideByZeroException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingIndexOutOfRangeException(string message) {
      SWIGPendingException.Set(new System.IndexOutOfRangeException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingInvalidCastException(string message) {
      SWIGPendingException.Set(new System.InvalidCastException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingInvalidOperationException(string message) {
      SWIGPendingException.Set(new System.InvalidOperationException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingIOException(string message) {
      SWIGPendingException.Set(new System.IO.IOException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingNullReferenceException(string message) {
      SWIGPendingException.Set(new System.NullReferenceException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingOutOfMemoryException(string message) {
      SWIGPendingException.Set(new System.OutOfMemoryException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingOverflowException(string message) {
      SWIGPendingException.Set(new System.OverflowException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingSystemException(string message) {
      SWIGPendingException.Set(new System.SystemException(message, SWIGPendingException.Retrieve()));
    }

    static void SetPendingArgumentException(string message, string paramName) {
      SWIGPendingException.Set(new System.ArgumentException(message, paramName, SWIGPendingException.Retrieve()));
    }
    static void SetPendingArgumentNullException(string message, string paramName) {
      Exception e = SWIGPendingException.Retrieve();
      if (e != null) message = message + " Inner Exception: " + e.Message;
      SWIGPendingException.Set(new System.ArgumentNullException(paramName, message));
    }
    static void SetPendingArgumentOutOfRangeException(string message, string paramName) {
      Exception e = SWIGPendingException.Retrieve();
      if (e != null) message = message + " Inner Exception: " + e.Message;
      SWIGPendingException.Set(new System.ArgumentOutOfRangeException(paramName, message));
    }

    static SWIGExceptionHelper() {
      SWIGRegisterExceptionCallbacks_djonwrapper(
                                applicationDelegate,
                                arithmeticDelegate,
                                divideByZeroDelegate,
                                indexOutOfRangeDelegate,
                                invalidCastDelegate,
                                invalidOperationDelegate,
                                ioDelegate,
                                nullReferenceDelegate,
                                outOfMemoryDelegate,
                                overflowDelegate,
                                systemDelegate);

      SWIGRegisterExceptionCallbacksArgument_djonwrapper(
                                argumentDelegate,
                                argumentNullDelegate,
                                argumentOutOfRangeDelegate);
    }
  }

  protected static SWIGExceptionHelper swigExceptionHelper = new SWIGExceptionHelper();

  public class SWIGPendingException {
    [ThreadStatic]
    private static Exception pendingException = null;
    private static int numExceptionsPending = 0;

    public static bool Pending {
      get {
        bool pending = false;
        if (numExceptionsPending > 0)
          if (pendingException != null)
            pending = true;
        return pending;
      } 
    }

    public static void Set(Exception e) {
      if (pendingException != null)
        throw new ApplicationException("FATAL: An earlier pending exception from unmanaged code was missed and thus not thrown (" + pendingException.ToString() + ")", e);
      pendingException = e;
      lock(typeof(djonwrapperPINVOKE)) {
        numExceptionsPending++;
      }
    }

    public static Exception Retrieve() {
      Exception e = null;
      if (numExceptionsPending > 0) {
        if (pendingException != null) {
          e = pendingException;
          pendingException = null;
          lock(typeof(djonwrapperPINVOKE)) {
            numExceptionsPending--;
          }
        }
      }
      return e;
    }
  }


  protected class SWIGStringHelper {

    public delegate string SWIGStringDelegate(string message);
    static SWIGStringDelegate stringDelegate = new SWIGStringDelegate(CreateString);

    [DllImport("djonwrapper", EntryPoint="SWIGRegisterStringCallback_djonwrapper")]
    public static extern void SWIGRegisterStringCallback_djonwrapper(SWIGStringDelegate stringDelegate);

    static string CreateString(string cString) {
      return cString;
    }

    static SWIGStringHelper() {
      SWIGRegisterStringCallback_djonwrapper(stringDelegate);
    }
  }

  static protected SWIGStringHelper swigStringHelper = new SWIGStringHelper();


  static djonwrapperPINVOKE() {
  }


  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_Clear")]
  public static extern void BSONObjVectorPtr_Clear(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_Add")]
  public static extern void BSONObjVectorPtr_Add(HandleRef jarg1, HandleRef jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_size")]
  public static extern uint BSONObjVectorPtr_size(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_capacity")]
  public static extern uint BSONObjVectorPtr_capacity(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_reserve")]
  public static extern void BSONObjVectorPtr_reserve(HandleRef jarg1, uint jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_new_BSONObjVectorPtr__SWIG_0")]
  public static extern IntPtr new_BSONObjVectorPtr__SWIG_0();

  [DllImport("djonwrapper", EntryPoint="CSharp_new_BSONObjVectorPtr__SWIG_1")]
  public static extern IntPtr new_BSONObjVectorPtr__SWIG_1(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_new_BSONObjVectorPtr__SWIG_2")]
  public static extern IntPtr new_BSONObjVectorPtr__SWIG_2(int jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_getitemcopy")]
  public static extern IntPtr BSONObjVectorPtr_getitemcopy(HandleRef jarg1, int jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_getitem")]
  public static extern IntPtr BSONObjVectorPtr_getitem(HandleRef jarg1, int jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_setitem")]
  public static extern void BSONObjVectorPtr_setitem(HandleRef jarg1, int jarg2, HandleRef jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_AddRange")]
  public static extern void BSONObjVectorPtr_AddRange(HandleRef jarg1, HandleRef jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_GetRange")]
  public static extern IntPtr BSONObjVectorPtr_GetRange(HandleRef jarg1, int jarg2, int jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_Insert")]
  public static extern void BSONObjVectorPtr_Insert(HandleRef jarg1, int jarg2, HandleRef jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_InsertRange")]
  public static extern void BSONObjVectorPtr_InsertRange(HandleRef jarg1, int jarg2, HandleRef jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_RemoveAt")]
  public static extern void BSONObjVectorPtr_RemoveAt(HandleRef jarg1, int jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_RemoveRange")]
  public static extern void BSONObjVectorPtr_RemoveRange(HandleRef jarg1, int jarg2, int jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_Repeat")]
  public static extern IntPtr BSONObjVectorPtr_Repeat(HandleRef jarg1, int jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_Reverse__SWIG_0")]
  public static extern void BSONObjVectorPtr_Reverse__SWIG_0(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_Reverse__SWIG_1")]
  public static extern void BSONObjVectorPtr_Reverse__SWIG_1(HandleRef jarg1, int jarg2, int jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_SetRange")]
  public static extern void BSONObjVectorPtr_SetRange(HandleRef jarg1, int jarg2, HandleRef jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_Contains")]
  public static extern bool BSONObjVectorPtr_Contains(HandleRef jarg1, HandleRef jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_IndexOf")]
  public static extern int BSONObjVectorPtr_IndexOf(HandleRef jarg1, HandleRef jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_LastIndexOf")]
  public static extern int BSONObjVectorPtr_LastIndexOf(HandleRef jarg1, HandleRef jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObjVectorPtr_Remove")]
  public static extern bool BSONObjVectorPtr_Remove(HandleRef jarg1, HandleRef jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_delete_BSONObjVectorPtr")]
  public static extern void delete_BSONObjVectorPtr(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_Clear")]
  public static extern void StringVector_Clear(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_Add")]
  public static extern void StringVector_Add(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_size")]
  public static extern uint StringVector_size(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_capacity")]
  public static extern uint StringVector_capacity(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_reserve")]
  public static extern void StringVector_reserve(HandleRef jarg1, uint jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_new_StringVector__SWIG_0")]
  public static extern IntPtr new_StringVector__SWIG_0();

  [DllImport("djonwrapper", EntryPoint="CSharp_new_StringVector__SWIG_1")]
  public static extern IntPtr new_StringVector__SWIG_1(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_new_StringVector__SWIG_2")]
  public static extern IntPtr new_StringVector__SWIG_2(int jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_getitemcopy")]
  public static extern string StringVector_getitemcopy(HandleRef jarg1, int jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_getitem")]
  public static extern string StringVector_getitem(HandleRef jarg1, int jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_setitem")]
  public static extern void StringVector_setitem(HandleRef jarg1, int jarg2, string jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_AddRange")]
  public static extern void StringVector_AddRange(HandleRef jarg1, HandleRef jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_GetRange")]
  public static extern IntPtr StringVector_GetRange(HandleRef jarg1, int jarg2, int jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_Insert")]
  public static extern void StringVector_Insert(HandleRef jarg1, int jarg2, string jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_InsertRange")]
  public static extern void StringVector_InsertRange(HandleRef jarg1, int jarg2, HandleRef jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_RemoveAt")]
  public static extern void StringVector_RemoveAt(HandleRef jarg1, int jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_RemoveRange")]
  public static extern void StringVector_RemoveRange(HandleRef jarg1, int jarg2, int jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_Repeat")]
  public static extern IntPtr StringVector_Repeat(string jarg1, int jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_Reverse__SWIG_0")]
  public static extern void StringVector_Reverse__SWIG_0(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_Reverse__SWIG_1")]
  public static extern void StringVector_Reverse__SWIG_1(HandleRef jarg1, int jarg2, int jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_SetRange")]
  public static extern void StringVector_SetRange(HandleRef jarg1, int jarg2, HandleRef jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_Contains")]
  public static extern bool StringVector_Contains(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_IndexOf")]
  public static extern int StringVector_IndexOf(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_LastIndexOf")]
  public static extern int StringVector_LastIndexOf(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_StringVector_Remove")]
  public static extern bool StringVector_Remove(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_delete_StringVector")]
  public static extern void delete_StringVector(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_new_BSONArrayObj__SWIG_0")]
  public static extern IntPtr new_BSONArrayObj__SWIG_0();

  [DllImport("djonwrapper", EntryPoint="CSharp_delete_BSONArrayObj")]
  public static extern void delete_BSONArrayObj(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_new_BSONArrayObj__SWIG_1")]
  public static extern IntPtr new_BSONArrayObj__SWIG_1(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONArrayObj_length")]
  public static extern int BSONArrayObj_length(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONArrayObj_add")]
  public static extern void BSONArrayObj_add(HandleRef jarg1, HandleRef jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONArrayObj_get")]
  public static extern IntPtr BSONArrayObj_get(HandleRef jarg1, int jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONArrayObj_toChar")]
  public static extern string BSONArrayObj_toChar(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONArrayObj_select")]
  public static extern IntPtr BSONArrayObj_select(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONArrayObj_begin")]
  public static extern IntPtr BSONArrayObj_begin(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONArrayObj_end")]
  public static extern IntPtr BSONArrayObj_end(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_new_BSONObj__SWIG_0")]
  public static extern IntPtr new_BSONObj__SWIG_0();

  [DllImport("djonwrapper", EntryPoint="CSharp_new_BSONObj__SWIG_1")]
  public static extern IntPtr new_BSONObj__SWIG_1(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_delete_BSONObj")]
  public static extern void delete_BSONObj(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_add__SWIG_0")]
  public static extern void BSONObj_add__SWIG_0(HandleRef jarg1, string jarg2, int jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_add__SWIG_1")]
  public static extern void BSONObj_add__SWIG_1(HandleRef jarg1, string jarg2, double jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_add__SWIG_2")]
  public static extern void BSONObj_add__SWIG_2(HandleRef jarg1, string jarg2, long jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_add__SWIG_3")]
  public static extern void BSONObj_add__SWIG_3(HandleRef jarg1, string jarg2, string jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_add__SWIG_4")]
  public static extern void BSONObj_add__SWIG_4(HandleRef jarg1, string jarg2, string jarg3, int jarg4);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_add__SWIG_5")]
  public static extern void BSONObj_add__SWIG_5(HandleRef jarg1, string jarg2, HandleRef jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_add__SWIG_6")]
  public static extern void BSONObj_add__SWIG_6(HandleRef jarg1, string jarg2, HandleRef jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_add__SWIG_7")]
  public static extern void BSONObj_add__SWIG_7(HandleRef jarg1, string jarg2, HandleRef jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_has")]
  public static extern bool BSONObj_has(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_getInt")]
  public static extern int BSONObj_getInt(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_getDouble")]
  public static extern double BSONObj_getDouble(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_getLong")]
  public static extern long BSONObj_getLong(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_getString")]
  public static extern string BSONObj_getString(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_getBSON")]
  public static extern IntPtr BSONObj_getBSON(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_getBSONArray")]
  public static extern IntPtr BSONObj_getBSONArray(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_get")]
  public static extern IntPtr BSONObj_get(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_getContent__SWIG_0")]
  public static extern IntPtr BSONObj_getContent__SWIG_0(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_getContent__SWIG_1")]
  public static extern IntPtr BSONObj_getContent__SWIG_1(HandleRef jarg1, string jarg2, HandleRef jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_getXpath")]
  public static extern IntPtr BSONObj_getXpath(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_select")]
  public static extern IntPtr BSONObj_select(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_type")]
  public static extern IntPtr BSONObj_type(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_toChar")]
  public static extern string BSONObj_toChar(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_begin")]
  public static extern IntPtr BSONObj_begin(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_end")]
  public static extern IntPtr BSONObj_end(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONObj_length")]
  public static extern int BSONObj_length(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_new_BSONParser")]
  public static extern IntPtr new_BSONParser();

  [DllImport("djonwrapper", EntryPoint="CSharp_delete_BSONParser")]
  public static extern void delete_BSONParser(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONParser_parse")]
  public static extern IntPtr BSONParser_parse(string jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_BSONParser_parseArray")]
  public static extern IntPtr BSONParser_parseArray(string jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_parseFilterOperator")]
  public static extern int parseFilterOperator(string jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_new_ParseException__SWIG_0")]
  public static extern IntPtr new_ParseException__SWIG_0(int jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_new_ParseException__SWIG_1")]
  public static extern IntPtr new_ParseException__SWIG_1(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_ParseException_what")]
  public static extern string ParseException_what(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_ParseException_errorCode")]
  public static extern int ParseException_errorCode(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_delete_ParseException")]
  public static extern void delete_ParseException(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_bson_splitSelect")]
  public static extern IntPtr bson_splitSelect(string jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_bson_subselect")]
  public static extern string bson_subselect(string jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_convert")]
  public static extern IntPtr convert(HandleRef jarg1, HandleRef jarg2, HandleRef jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_SERVER_PORT_get")]
  public static extern int SERVER_PORT_get();

  [DllImport("djonwrapper", EntryPoint="CSharp_new_DjondbConnection__SWIG_0")]
  public static extern IntPtr new_DjondbConnection__SWIG_0(string jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_new_DjondbConnection__SWIG_1")]
  public static extern IntPtr new_DjondbConnection__SWIG_1(string jarg1, int jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_new_DjondbConnection__SWIG_2")]
  public static extern IntPtr new_DjondbConnection__SWIG_2(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_delete_DjondbConnection")]
  public static extern void delete_DjondbConnection(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_beginTransaction")]
  public static extern string DjondbConnection_beginTransaction(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_commitTransaction")]
  public static extern void DjondbConnection_commitTransaction(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_rollbackTransaction")]
  public static extern void DjondbConnection_rollbackTransaction(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_open")]
  public static extern bool DjondbConnection_open(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_close")]
  public static extern void DjondbConnection_close(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_internalClose")]
  public static extern void DjondbConnection_internalClose(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_isOpen")]
  public static extern bool DjondbConnection_isOpen(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_shutdown")]
  public static extern bool DjondbConnection_shutdown(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_insert__SWIG_0")]
  public static extern bool DjondbConnection_insert__SWIG_0(HandleRef jarg1, string jarg2, string jarg3, string jarg4);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_insert__SWIG_1")]
  public static extern bool DjondbConnection_insert__SWIG_1(HandleRef jarg1, string jarg2, string jarg3, HandleRef jarg4);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_findByKey__SWIG_0")]
  public static extern IntPtr DjondbConnection_findByKey__SWIG_0(HandleRef jarg1, string jarg2, string jarg3, string jarg4, string jarg5);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_findByKey__SWIG_1")]
  public static extern IntPtr DjondbConnection_findByKey__SWIG_1(HandleRef jarg1, string jarg2, string jarg3, string jarg4);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_find__SWIG_0")]
  public static extern IntPtr DjondbConnection_find__SWIG_0(HandleRef jarg1, string jarg2, string jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_find__SWIG_1")]
  public static extern IntPtr DjondbConnection_find__SWIG_1(HandleRef jarg1, string jarg2, string jarg3, HandleRef jarg4);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_find__SWIG_2")]
  public static extern IntPtr DjondbConnection_find__SWIG_2(HandleRef jarg1, string jarg2, string jarg3, string jarg4);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_find__SWIG_3")]
  public static extern IntPtr DjondbConnection_find__SWIG_3(HandleRef jarg1, string jarg2, string jarg3, string jarg4, HandleRef jarg5);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_find__SWIG_4")]
  public static extern IntPtr DjondbConnection_find__SWIG_4(HandleRef jarg1, string jarg2, string jarg3, string jarg4, string jarg5);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_find__SWIG_5")]
  public static extern IntPtr DjondbConnection_find__SWIG_5(HandleRef jarg1, string jarg2, string jarg3, string jarg4, string jarg5, HandleRef jarg6);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_update__SWIG_0")]
  public static extern bool DjondbConnection_update__SWIG_0(HandleRef jarg1, string jarg2, string jarg3, string jarg4);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_update__SWIG_1")]
  public static extern bool DjondbConnection_update__SWIG_1(HandleRef jarg1, string jarg2, string jarg3, HandleRef jarg4);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_remove")]
  public static extern bool DjondbConnection_remove(HandleRef jarg1, string jarg2, string jarg3, string jarg4, string jarg5);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_executeQuery")]
  public static extern IntPtr DjondbConnection_executeQuery(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_executeUpdate")]
  public static extern bool DjondbConnection_executeUpdate(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_dropNamespace")]
  public static extern bool DjondbConnection_dropNamespace(HandleRef jarg1, string jarg2, string jarg3);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_dbs")]
  public static extern IntPtr DjondbConnection_dbs(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_namespaces")]
  public static extern IntPtr DjondbConnection_namespaces(HandleRef jarg1, string jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnection_host")]
  public static extern string DjondbConnection_host(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_ConnectionReference__connection_set")]
  public static extern void ConnectionReference__connection_set(HandleRef jarg1, HandleRef jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_ConnectionReference__connection_get")]
  public static extern IntPtr ConnectionReference__connection_get(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_ConnectionReference__references_set")]
  public static extern void ConnectionReference__references_set(HandleRef jarg1, int jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_ConnectionReference__references_get")]
  public static extern int ConnectionReference__references_get(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_new_ConnectionReference")]
  public static extern IntPtr new_ConnectionReference();

  [DllImport("djonwrapper", EntryPoint="CSharp_delete_ConnectionReference")]
  public static extern void delete_ConnectionReference(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_new_DjondbConnectionManager")]
  public static extern IntPtr new_DjondbConnectionManager();

  [DllImport("djonwrapper", EntryPoint="CSharp_delete_DjondbConnectionManager")]
  public static extern void delete_DjondbConnectionManager(HandleRef jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnectionManager_getConnection__SWIG_0")]
  public static extern IntPtr DjondbConnectionManager_getConnection__SWIG_0(string jarg1);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnectionManager_getConnection__SWIG_1")]
  public static extern IntPtr DjondbConnectionManager_getConnection__SWIG_1(string jarg1, int jarg2);

  [DllImport("djonwrapper", EntryPoint="CSharp_DjondbConnectionManager_releaseConnection")]
  public static extern void DjondbConnectionManager_releaseConnection(HandleRef jarg1);
}

}
