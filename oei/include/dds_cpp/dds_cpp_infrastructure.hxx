#ifndef dds_cpp_infrastructure_hxx
#define dds_cpp_infrastructure_hxx

/*i @file
  @ingroup DDSInfrastructureModule

  @brief Defines the \dds infrastructure package
*/

#ifndef dds_cpp_dll_hxx
  #include "dds_cpp/dds_cpp_dll.hxx"
#endif

#ifndef dds_c_infrastructure_h
  #include "dds_c/dds_c_infrastructure.h"
#endif


/* ================================================================= */
/*                 Listeners                                         */
/* ================================================================= */

/*e \dref_Listener
 */
class DDSCPPDllExport DDSListener 
{

  protected:
    DDSListener() { }
    virtual ~DDSListener() { }
};

/* ================================================================= */
/*                         Conditions                                */
/* ================================================================= */
class DDSWaitSet;
class DDSCondition;

class DDSCPPDllExport DDSConditionSeq
{
  friend class DDSWaitSet;

  public:
    OEI_INT32 maximum() const;
    bool maximum(OEI_INT32 new_max);
    OEI_INT32 length() const;
    bool length(OEI_INT32 new_length);
    DDSCondition** get_reference(OEI_INT32 i);
    DDSConditionSeq();
    ~DDSConditionSeq();
#ifdef OEI_CERT
  private:
#else
  public:
#endif
    bool copy(const DDSConditionSeq& other);
    bool is_equal(const DDSConditionSeq& other) const;
    bool operator==(const DDSConditionSeq& other) const;
    bool operator!=(const DDSConditionSeq& other) const;
    DDSCondition *const & operator[](OEI_INT32 i) const;
    DDSCondition*& operator[](OEI_INT32 i);
    DDSConditionSeq& operator=(const DDSConditionSeq&);
    DDSConditionSeq(const DDSConditionSeq&);
    bool ensure_length(OEI_INT32 len, OEI_INT32 max);

  private:
    DDS_ConditionSeq _c_seq;
};

class DDSCPPDllExport DDSCondition
{
  friend class DDSWaitSet;

  public:

    virtual bool get_trigger_value();

  protected:
    DDSCondition(DDS_Condition *c_cond);

    virtual ~DDSCondition();

    DDS_Condition *_c_cond;

};


/* -----------------------------------------------------------------*/

class DDSCPPDllExport DDSGuardCondition : public DDSCondition {    
  public: 
    
    DDS_ReturnCode_t set_trigger_value(bool value);
    
  public:

    DDSGuardCondition();
    
    virtual ~DDSGuardCondition();
};


/* -----------------------------------------------------------------*/
class DDSEntity;
class DDSCPPDllExport DDSStatusCondition : public DDSCondition {
  friend class DDSEntity;

  public:
    
    DDS_StatusMask get_enabled_statuses();
    
    DDS_ReturnCode_t set_enabled_statuses(DDS_StatusMask mask);

    DDSEntity* get_entity();

  protected:
    DDSStatusCondition(DDS_StatusCondition *c_cond);
    virtual ~DDSStatusCondition();
};

/* ----------------------------------------------------------------- */

class DDSCPPDllExport DDSWaitSet {
  public:

    DDS_ReturnCode_t wait(DDSConditionSeq& active_conditions,
                          const DDS_Duration_t& timeout);

    DDS_ReturnCode_t attach_condition(DDSCondition* cond);

    DDS_ReturnCode_t detach_condition(DDSCondition* cond);

    DDS_ReturnCode_t get_conditions(DDSConditionSeq& attached_conditions);

  public:

    virtual ~DDSWaitSet();

    DDSWaitSet();

  private:

    /*i
      @brief The underlying implementation object owned by this class.
     */
    DDS_WaitSet* _c_impl;
};

/* ================================================================= */
/*                      DDSEntity                                       */
/* ================================================================= */ 

/* ----------------------------------------------------------------- */
/*e \dref_Entity
 */
class DDSCPPDllExport DDSEntity
{

  public: 
    
    /*e \dref_Entity_enable
     */
    DDS_ReturnCode_t enable();
    
    /*e \dref_Entity_get_statuscondition
     */
    DDSStatusCondition *get_statuscondition();
        
    /*e \dref_Entity_get_status_changes
     */
    DDS_StatusMask get_status_changes();
    
    /*i
     * Return a reference to the underlying C entity.
     */
    DDS_Entity* get_c_entity();

  protected:

    DDSEntity(DDS_Entity *c_entity);
    virtual ~DDSEntity();

    DDS_Entity *_c_entity;
};  


#endif
