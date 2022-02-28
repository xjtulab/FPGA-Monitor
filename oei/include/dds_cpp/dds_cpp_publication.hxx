#ifndef dds_cpp_publication_hxx
#define dds_cpp_publication_hxx

/*i @file
  @ingroup DDSPublicationModule

  @brief Defines the \dds publication package
*/

#ifndef dds_cpp_dll_hxx
  #include "dds_cpp/dds_cpp_dll.hxx"
#endif
#ifndef dds_cpp_infrastructure_hxx
  #include "dds_cpp/dds_cpp_infrastructure.hxx"
#endif
#ifndef dds_cpp_topic_hxx
  #include "dds_cpp/dds_cpp_topic.hxx"
#endif
#ifndef dds_c_publication_h
  #include "dds_c/dds_c_publication.h"
#endif


/* ================================================================= */
/*                       Listeners                                   */
/* ================================================================= */

class DDSDataWriter;

/* -------------------------------*/
/* Data Writer Listener interface */
/* -------------------------------*/

/* ----------------------------------------------------------------- */
/*e \dref_DataWriterListener
 */
class DDSCPPDllExport DDSDataWriterListener : public virtual DDSListener 
{
  public:
    /*e \dref_DataWriterListener_on_offered_deadline_missed
     */
    virtual void on_offered_deadline_missed(
            DDSDataWriter *,
            const DDS_OfferedDeadlineMissedStatus&) { }

    /*e \dref_DataWriterListener_on_liveliness_lost
     */
    virtual void on_liveliness_lost(
            DDSDataWriter *,
            const DDS_LivelinessLostStatus&) { }

    /*e \dref_DataWriterListener_on_offered_incompatible_qos
     */
    virtual void on_offered_incompatible_qos(
            DDSDataWriter *,
            const DDS_OfferedIncompatibleQosStatus&) { }

    /*e \dref_DataWriterListener_on_publication_matched
     */
    virtual void on_publication_matched(
            DDSDataWriter *,
            const DDS_PublicationMatchedStatus&) { }

    /*e \dref_DataWriterListener_on_reliable_reader_activity_changed
     */
    virtual void on_reliable_reader_activity_changed(
            DDSDataWriter *,
            const DDS_ReliableReaderActivityChangedStatus&) { }

    /*e \dref_DataWriterListener_on_reliable_sample_unacknowledged
         */
    virtual void on_reliable_sample_unacknowledged(
            DDSDataWriter *,
            const DDS_ReliableSampleUnacknowledgedStatus&) { }


  public:
    DDSDataWriterListener() { }
    virtual ~DDSDataWriterListener() { }

};

class DDSPublisher;

/* -------------------------------*/
/* Publisher Listener interface   */
/* -------------------------------*/

/* ----------------------------------------------------------------- */
/*e \dref_PublisherListener
 */
class DDSCPPDllExport DDSPublisherListener : public virtual DDSDataWriterListener 
{
  public:
    DDSPublisherListener() { }
    virtual ~DDSPublisherListener() { }
};

/* ================================================================= */
/*                            Entity                                 */
/* ================================================================= */

class DDSPublisher;

class DDSDomainParticipant;
class DDSTopic;
/* ----------------------------------------------------------------- */
/*e \dref_Publisher
 */
class DDSCPPDllExport DDSPublisher : public DDSEntity 
{
  // --- <<interface>> DDSPublisher: -----------------------------------
  public:
    /*e \dref_Publisher_as_entity
     */
    virtual DDSEntity* as_entity() = 0;

    /*e \dref_Publisher_create_datawriter
     */
    virtual DDSDataWriter* create_datawriter(
            DDSTopic* topic,
            const DDS_DataWriterQos& qos,
            DDSDataWriterListener* listener,
            DDS_StatusMask mask) = 0;

    /*e \dref_Publisher_delete_datawriter
     */
    virtual DDS_ReturnCode_t delete_datawriter(
            DDSDataWriter* a_datawriter) = 0;

    /*e \dref_Publisher_get_default_datawriter_qos
     */
    virtual DDS_ReturnCode_t get_default_datawriter_qos(
            DDS_DataWriterQos& qos) = 0;

    /*e \dref_Publisher_set_default_datawriter_qos
     */
    virtual DDS_ReturnCode_t set_default_datawriter_qos(
            const DDS_DataWriterQos& qos) = 0;

    /*e \dref_Publisher_lookup_datawriter
     */
    virtual DDSDataWriter* lookup_datawriter(
            const char* topic_name) = 0;

    /*e \dref_Publisher_get_participant
     */
    virtual DDSDomainParticipant* get_participant() = 0;

    /*e \dref_Publisher_get_qos
     */
    virtual DDS_ReturnCode_t get_qos(
            DDS_PublisherQos& qos) = 0;

    /*e \dref_Publisher_set_qos
     */
    virtual DDS_ReturnCode_t set_qos(
            const DDS_PublisherQos& qos) = 0;

    /*e \dref_Publisher_delete_contained_entities
     */
    virtual DDS_ReturnCode_t delete_contained_entities() = 0;

    /*e \dref_Publisher_set_listener
     */
    virtual DDS_ReturnCode_t set_listener(
            const DDSPublisherListener *listener,
            DDS_StatusMask mask) = 0;

    /*e \dref_Publisher_get_listener
     */
    virtual DDSPublisherListener* get_listener() = 0;

  protected: 

    // --- <<lifecycle>>: ------------------------------------------------
    DDSPublisher(DDS_Publisher *c_publisher);

    ~DDSPublisher();

};


struct DDS_SubscriptionBuiltinTopicData;
/* ----------------------------------------------------------------- */
/*e \dref_DataWriter
 */
class DDSCPPDllExport DDSDataWriter : public DDSEntity 
{

  public:
    /*e \dref_DataWriter_as_entity
     */
    virtual DDSEntity* as_entity() = 0;

    // --- Untyped endpoint methods ------------------------------------------

    /*e \dref_DataWriter_write_untyped
     */
    virtual DDS_ReturnCode_t write_untyped(
            const void* instance_data,
            const DDS_InstanceHandle_t& handle) = 0;

    /*e \dref_DataWriter_assert_liveliness
     */
    virtual DDS_ReturnCode_t assert_liveliness() = 0;

    /*e \dref_DataWriter_get_topic
     */
    virtual DDSTopic* get_topic() = 0;

    /*e \dref_DataWriter_get_publisher
     */
    virtual DDSPublisher* get_publisher() = 0;

    /*e \dref_DataWriter_get_qos
     */
    virtual DDS_ReturnCode_t get_qos(
            DDS_DataWriterQos& qos) = 0;

    /*e \dref_DataWriter_set_qos
     */
    virtual DDS_ReturnCode_t set_qos(
            const DDS_DataWriterQos& qos) = 0;

    /*e \dref_DataWriter_set_listener
     */
    virtual DDS_ReturnCode_t set_listener(
            const DDSDataWriterListener *listener,
            DDS_StatusMask mask) = 0;

    /*e \dref_DataWriter_get_listener
     */
    virtual DDSDataWriterListener* get_listener() = 0;

    /*e \dref_DataWriter_register_instance_untyped
     */
    virtual DDS_InstanceHandle_t register_instance_untyped(
            const void *instance_data) = 0;

    /*e \dref_DataWriter_register_instance_w_timestamp
     */
    virtual DDS_InstanceHandle_t register_instance_w_timestamp_untyped(
            const void *instance_data,
            const DDS_Time_t& source_timestamp) = 0;

    /*e \dref_DataWriter_unregister_instance_untyped
     */
    virtual DDS_ReturnCode_t unregister_instance_untyped(
            const void *instance_data,
            const DDS_InstanceHandle_t& handle) = 0;

    /*e \dref_DataWriter_unregister_instance_w_timestamp
     */
    virtual DDS_ReturnCode_t unregister_instance_w_timestamp_untyped(
            const void *instance_data,
            const DDS_InstanceHandle_t& handle,
            const DDS_Time_t& source_timestamp) = 0;

    /*e \dref_DataWriter_dispose
     */
    virtual DDS_ReturnCode_t dispose_untyped(
            const void *instance_data,
            const DDS_InstanceHandle_t& handle) = 0;

    /*e \dref_DataWriter_dispose_w_timestamp
     */
    virtual DDS_ReturnCode_t dispose_w_timestamp_untyped(
            const void *instance_data,
            const DDS_InstanceHandle_t& handle,
            const DDS_Time_t& source_timestamp) = 0;

    /*e \dref_DataWriter_write_w_timestamp_untyped
     */
    virtual DDS_ReturnCode_t write_w_timestamp_untyped(
            const void *instance_data,
            const DDS_InstanceHandle_t& handle,
            const DDS_Time_t& source_timestamp) = 0;

     /*e \dref_DataWriter_get_publication_matched_status
     */
    virtual DDS_ReturnCode_t get_publication_matched_status(
            DDS_PublicationMatchedStatus& status) = 0;

    /*e \dref_DataWriter_get_liveliness_lost_status
     */
    virtual DDS_ReturnCode_t get_liveliness_lost_status(
            DDS_LivelinessLostStatus& status) = 0;

    /*e \dref_DataWriter_get_offered_deadline_missed_status
     */
    virtual DDS_ReturnCode_t get_offered_deadline_missed_status(
            DDS_OfferedDeadlineMissedStatus& status) = 0;

    /*e \dref_DataWriter_get_offered_incompatible_qos_status
     */
    virtual DDS_ReturnCode_t get_offered_incompatible_qos_status(
            DDS_OfferedIncompatibleQosStatus& status) = 0;

  protected:
    // --- <<constructor/destructor>> ---------------------------------------
    DDSDataWriter(DDS_DataWriter* c_writer);

    ~DDSDataWriter();
};

class DDSPublisher_impl;

class DDSCPPDllExport DDSDataWriter_impl : public DDSDataWriter
{

  friend class DDSPublisher_impl;

  public:

    DDSEntity* as_entity();

    // --- Untyped endpoint methods ------------------------------------------
    DDS_ReturnCode_t write_untyped(
            const void* instance_data,
            const DDS_InstanceHandle_t& handle);

    DDS_ReturnCode_t assert_liveliness();

    DDSTopic* get_topic();

    DDSPublisher* get_publisher();

    DDS_ReturnCode_t get_qos(DDS_DataWriterQos& qos);

    DDS_ReturnCode_t set_qos(const DDS_DataWriterQos& qos);

    DDS_ReturnCode_t set_listener(
            const DDSDataWriterListener *l,
            DDS_StatusMask mask);

    DDSDataWriterListener* get_listener();

    DDS_InstanceHandle_t register_instance_untyped(
            const void *instance_data);

    DDS_InstanceHandle_t register_instance_w_timestamp_untyped(
            const void *instance_data,
            const DDS_Time_t& source_timestamp);

    DDS_ReturnCode_t unregister_instance_untyped(
            const void *instance_data,
            const DDS_InstanceHandle_t& handle);

    DDS_ReturnCode_t unregister_instance_w_timestamp_untyped(
            const void *instance_data,
            const DDS_InstanceHandle_t& handle,
            const DDS_Time_t& source_timestamp);

    DDS_ReturnCode_t dispose_untyped(
            const void *instance_data,
            const DDS_InstanceHandle_t& handle);

    DDS_ReturnCode_t dispose_w_timestamp_untyped(
            const void *instance_data,
            const DDS_InstanceHandle_t& handle,
            const DDS_Time_t& source_timestamp);

    DDS_ReturnCode_t write_w_timestamp_untyped(
            const void *instance_data,
            const DDS_InstanceHandle_t& handle,
            const DDS_Time_t& source_timestamp);

    DDS_ReturnCode_t get_publication_matched_status(
            DDS_PublicationMatchedStatus& status);

    DDS_ReturnCode_t get_liveliness_lost_status(
            DDS_LivelinessLostStatus& status);

    DDS_ReturnCode_t get_offered_deadline_missed_status(
            DDS_OfferedDeadlineMissedStatus& status);

    DDS_ReturnCode_t get_offered_incompatible_qos_status(
            DDS_OfferedIncompatibleQosStatus& status);

    DDS_ReturnCode_t get_reliable_reader_activity_changed_status(
            DDS_ReliableReaderActivityChangedStatus& status);

  protected:
    // --- <<constructor/destructor>> ---------------------------------------
    DDSDataWriter_impl(DDS_DataWriter* c_writer);

    ~DDSDataWriter_impl();

};

#endif /* dds_cpp_publication_hxx */

