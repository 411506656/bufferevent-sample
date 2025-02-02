// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mirroring.proto

#ifndef PROTOBUF_mirroring_2eproto__INCLUDED
#define PROTOBUF_mirroring_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003002 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace rbs {
class MirrorSwitch;
class MirrorSwitchDefaultTypeInternal;
extern MirrorSwitchDefaultTypeInternal _MirrorSwitch_default_instance_;
class MirroringReplay;
class MirroringReplayDefaultTypeInternal;
extern MirroringReplayDefaultTypeInternal _MirroringReplay_default_instance_;
class MirroringReport;
class MirroringReportDefaultTypeInternal;
extern MirroringReportDefaultTypeInternal _MirroringReport_default_instance_;
class MirroringRequest;
class MirroringRequestDefaultTypeInternal;
extern MirroringRequestDefaultTypeInternal _MirroringRequest_default_instance_;
}  // namespace rbs

namespace rbs {

namespace protobuf_mirroring_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_mirroring_2eproto

// ===================================================================

class MirroringReport : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:rbs.MirroringReport) */ {
 public:
  MirroringReport();
  virtual ~MirroringReport();

  MirroringReport(const MirroringReport& from);

  inline MirroringReport& operator=(const MirroringReport& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MirroringReport& default_instance();

  static inline const MirroringReport* internal_default_instance() {
    return reinterpret_cast<const MirroringReport*>(
               &_MirroringReport_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(MirroringReport* other);

  // implements Message ----------------------------------------------

  inline MirroringReport* New() const PROTOBUF_FINAL { return New(NULL); }

  MirroringReport* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const MirroringReport& from);
  void MergeFrom(const MirroringReport& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(MirroringReport* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string rtspserverurl = 3;
  void clear_rtspserverurl();
  static const int kRtspserverurlFieldNumber = 3;
  const ::std::string& rtspserverurl() const;
  void set_rtspserverurl(const ::std::string& value);
  #if LANG_CXX11
  void set_rtspserverurl(::std::string&& value);
  #endif
  void set_rtspserverurl(const char* value);
  void set_rtspserverurl(const char* value, size_t size);
  ::std::string* mutable_rtspserverurl();
  ::std::string* release_rtspserverurl();
  void set_allocated_rtspserverurl(::std::string* rtspserverurl);

  // string localmac = 4;
  void clear_localmac();
  static const int kLocalmacFieldNumber = 4;
  const ::std::string& localmac() const;
  void set_localmac(const ::std::string& value);
  #if LANG_CXX11
  void set_localmac(::std::string&& value);
  #endif
  void set_localmac(const char* value);
  void set_localmac(const char* value, size_t size);
  ::std::string* mutable_localmac();
  ::std::string* release_localmac();
  void set_allocated_localmac(::std::string* localmac);

  // int32 devicetype = 1;
  void clear_devicetype();
  static const int kDevicetypeFieldNumber = 1;
  ::google::protobuf::int32 devicetype() const;
  void set_devicetype(::google::protobuf::int32 value);

  // bool isstreamready = 2;
  void clear_isstreamready();
  static const int kIsstreamreadyFieldNumber = 2;
  bool isstreamready() const;
  void set_isstreamready(bool value);

  // @@protoc_insertion_point(class_scope:rbs.MirroringReport)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr rtspserverurl_;
  ::google::protobuf::internal::ArenaStringPtr localmac_;
  ::google::protobuf::int32 devicetype_;
  bool isstreamready_;
  mutable int _cached_size_;
  friend struct protobuf_mirroring_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class MirrorSwitch : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:rbs.MirrorSwitch) */ {
 public:
  MirrorSwitch();
  virtual ~MirrorSwitch();

  MirrorSwitch(const MirrorSwitch& from);

  inline MirrorSwitch& operator=(const MirrorSwitch& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MirrorSwitch& default_instance();

  static inline const MirrorSwitch* internal_default_instance() {
    return reinterpret_cast<const MirrorSwitch*>(
               &_MirrorSwitch_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(MirrorSwitch* other);

  // implements Message ----------------------------------------------

  inline MirrorSwitch* New() const PROTOBUF_FINAL { return New(NULL); }

  MirrorSwitch* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const MirrorSwitch& from);
  void MergeFrom(const MirrorSwitch& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(MirrorSwitch* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // uint64 timestamp = 1;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 1;
  ::google::protobuf::uint64 timestamp() const;
  void set_timestamp(::google::protobuf::uint64 value);

  // bool isbreak = 2;
  void clear_isbreak();
  static const int kIsbreakFieldNumber = 2;
  bool isbreak() const;
  void set_isbreak(bool value);

  // @@protoc_insertion_point(class_scope:rbs.MirrorSwitch)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 timestamp_;
  bool isbreak_;
  mutable int _cached_size_;
  friend struct protobuf_mirroring_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class MirroringRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:rbs.MirroringRequest) */ {
 public:
  MirroringRequest();
  virtual ~MirroringRequest();

  MirroringRequest(const MirroringRequest& from);

  inline MirroringRequest& operator=(const MirroringRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MirroringRequest& default_instance();

  enum MirroringMSGCase {
    kReport = 2,
    MIRRORING_MSG_NOT_SET = 0,
  };

  static inline const MirroringRequest* internal_default_instance() {
    return reinterpret_cast<const MirroringRequest*>(
               &_MirroringRequest_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(MirroringRequest* other);

  // implements Message ----------------------------------------------

  inline MirroringRequest* New() const PROTOBUF_FINAL { return New(NULL); }

  MirroringRequest* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const MirroringRequest& from);
  void MergeFrom(const MirroringRequest& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(MirroringRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string err = 99;
  void clear_err();
  static const int kErrFieldNumber = 99;
  const ::std::string& err() const;
  void set_err(const ::std::string& value);
  #if LANG_CXX11
  void set_err(::std::string&& value);
  #endif
  void set_err(const char* value);
  void set_err(const char* value, size_t size);
  ::std::string* mutable_err();
  ::std::string* release_err();
  void set_allocated_err(::std::string* err);

  // int32 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

  // .rbs.MirroringReport report = 2;
  bool has_report() const;
  void clear_report();
  static const int kReportFieldNumber = 2;
  const ::rbs::MirroringReport& report() const;
  ::rbs::MirroringReport* mutable_report();
  ::rbs::MirroringReport* release_report();
  void set_allocated_report(::rbs::MirroringReport* report);

  MirroringMSGCase Mirroring_MSG_case() const;
  // @@protoc_insertion_point(class_scope:rbs.MirroringRequest)
 private:
  void set_has_report();

  inline bool has_Mirroring_MSG() const;
  void clear_Mirroring_MSG();
  inline void clear_has_Mirroring_MSG();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr err_;
  ::google::protobuf::int32 id_;
  union MirroringMSGUnion {
    MirroringMSGUnion() {}
    ::rbs::MirroringReport* report_;
  } Mirroring_MSG_;
  mutable int _cached_size_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend struct protobuf_mirroring_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class MirroringReplay : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:rbs.MirroringReplay) */ {
 public:
  MirroringReplay();
  virtual ~MirroringReplay();

  MirroringReplay(const MirroringReplay& from);

  inline MirroringReplay& operator=(const MirroringReplay& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MirroringReplay& default_instance();

  enum MirroringMSGCase {
    kSwitchon = 2,
    MIRRORING_MSG_NOT_SET = 0,
  };

  static inline const MirroringReplay* internal_default_instance() {
    return reinterpret_cast<const MirroringReplay*>(
               &_MirroringReplay_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(MirroringReplay* other);

  // implements Message ----------------------------------------------

  inline MirroringReplay* New() const PROTOBUF_FINAL { return New(NULL); }

  MirroringReplay* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const MirroringReplay& from);
  void MergeFrom(const MirroringReplay& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(MirroringReplay* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string err = 99;
  void clear_err();
  static const int kErrFieldNumber = 99;
  const ::std::string& err() const;
  void set_err(const ::std::string& value);
  #if LANG_CXX11
  void set_err(::std::string&& value);
  #endif
  void set_err(const char* value);
  void set_err(const char* value, size_t size);
  ::std::string* mutable_err();
  ::std::string* release_err();
  void set_allocated_err(::std::string* err);

  // int32 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

  // .rbs.MirrorSwitch switchon = 2;
  bool has_switchon() const;
  void clear_switchon();
  static const int kSwitchonFieldNumber = 2;
  const ::rbs::MirrorSwitch& switchon() const;
  ::rbs::MirrorSwitch* mutable_switchon();
  ::rbs::MirrorSwitch* release_switchon();
  void set_allocated_switchon(::rbs::MirrorSwitch* switchon);

  MirroringMSGCase Mirroring_MSG_case() const;
  // @@protoc_insertion_point(class_scope:rbs.MirroringReplay)
 private:
  void set_has_switchon();

  inline bool has_Mirroring_MSG() const;
  void clear_Mirroring_MSG();
  inline void clear_has_Mirroring_MSG();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr err_;
  ::google::protobuf::int32 id_;
  union MirroringMSGUnion {
    MirroringMSGUnion() {}
    ::rbs::MirrorSwitch* switchon_;
  } Mirroring_MSG_;
  mutable int _cached_size_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend struct protobuf_mirroring_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// MirroringReport

// int32 devicetype = 1;
inline void MirroringReport::clear_devicetype() {
  devicetype_ = 0;
}
inline ::google::protobuf::int32 MirroringReport::devicetype() const {
  // @@protoc_insertion_point(field_get:rbs.MirroringReport.devicetype)
  return devicetype_;
}
inline void MirroringReport::set_devicetype(::google::protobuf::int32 value) {
  
  devicetype_ = value;
  // @@protoc_insertion_point(field_set:rbs.MirroringReport.devicetype)
}

// bool isstreamready = 2;
inline void MirroringReport::clear_isstreamready() {
  isstreamready_ = false;
}
inline bool MirroringReport::isstreamready() const {
  // @@protoc_insertion_point(field_get:rbs.MirroringReport.isstreamready)
  return isstreamready_;
}
inline void MirroringReport::set_isstreamready(bool value) {
  
  isstreamready_ = value;
  // @@protoc_insertion_point(field_set:rbs.MirroringReport.isstreamready)
}

// string rtspserverurl = 3;
inline void MirroringReport::clear_rtspserverurl() {
  rtspserverurl_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MirroringReport::rtspserverurl() const {
  // @@protoc_insertion_point(field_get:rbs.MirroringReport.rtspserverurl)
  return rtspserverurl_.GetNoArena();
}
inline void MirroringReport::set_rtspserverurl(const ::std::string& value) {
  
  rtspserverurl_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:rbs.MirroringReport.rtspserverurl)
}
#if LANG_CXX11
inline void MirroringReport::set_rtspserverurl(::std::string&& value) {
  
  rtspserverurl_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:rbs.MirroringReport.rtspserverurl)
}
#endif
inline void MirroringReport::set_rtspserverurl(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  rtspserverurl_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:rbs.MirroringReport.rtspserverurl)
}
inline void MirroringReport::set_rtspserverurl(const char* value, size_t size) {
  
  rtspserverurl_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:rbs.MirroringReport.rtspserverurl)
}
inline ::std::string* MirroringReport::mutable_rtspserverurl() {
  
  // @@protoc_insertion_point(field_mutable:rbs.MirroringReport.rtspserverurl)
  return rtspserverurl_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MirroringReport::release_rtspserverurl() {
  // @@protoc_insertion_point(field_release:rbs.MirroringReport.rtspserverurl)
  
  return rtspserverurl_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MirroringReport::set_allocated_rtspserverurl(::std::string* rtspserverurl) {
  if (rtspserverurl != NULL) {
    
  } else {
    
  }
  rtspserverurl_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), rtspserverurl);
  // @@protoc_insertion_point(field_set_allocated:rbs.MirroringReport.rtspserverurl)
}

// string localmac = 4;
inline void MirroringReport::clear_localmac() {
  localmac_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MirroringReport::localmac() const {
  // @@protoc_insertion_point(field_get:rbs.MirroringReport.localmac)
  return localmac_.GetNoArena();
}
inline void MirroringReport::set_localmac(const ::std::string& value) {
  
  localmac_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:rbs.MirroringReport.localmac)
}
#if LANG_CXX11
inline void MirroringReport::set_localmac(::std::string&& value) {
  
  localmac_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:rbs.MirroringReport.localmac)
}
#endif
inline void MirroringReport::set_localmac(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  localmac_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:rbs.MirroringReport.localmac)
}
inline void MirroringReport::set_localmac(const char* value, size_t size) {
  
  localmac_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:rbs.MirroringReport.localmac)
}
inline ::std::string* MirroringReport::mutable_localmac() {
  
  // @@protoc_insertion_point(field_mutable:rbs.MirroringReport.localmac)
  return localmac_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MirroringReport::release_localmac() {
  // @@protoc_insertion_point(field_release:rbs.MirroringReport.localmac)
  
  return localmac_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MirroringReport::set_allocated_localmac(::std::string* localmac) {
  if (localmac != NULL) {
    
  } else {
    
  }
  localmac_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), localmac);
  // @@protoc_insertion_point(field_set_allocated:rbs.MirroringReport.localmac)
}

// -------------------------------------------------------------------

// MirrorSwitch

// uint64 timestamp = 1;
inline void MirrorSwitch::clear_timestamp() {
  timestamp_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 MirrorSwitch::timestamp() const {
  // @@protoc_insertion_point(field_get:rbs.MirrorSwitch.timestamp)
  return timestamp_;
}
inline void MirrorSwitch::set_timestamp(::google::protobuf::uint64 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:rbs.MirrorSwitch.timestamp)
}

// bool isbreak = 2;
inline void MirrorSwitch::clear_isbreak() {
  isbreak_ = false;
}
inline bool MirrorSwitch::isbreak() const {
  // @@protoc_insertion_point(field_get:rbs.MirrorSwitch.isbreak)
  return isbreak_;
}
inline void MirrorSwitch::set_isbreak(bool value) {
  
  isbreak_ = value;
  // @@protoc_insertion_point(field_set:rbs.MirrorSwitch.isbreak)
}

// -------------------------------------------------------------------

// MirroringRequest

// int32 id = 1;
inline void MirroringRequest::clear_id() {
  id_ = 0;
}
inline ::google::protobuf::int32 MirroringRequest::id() const {
  // @@protoc_insertion_point(field_get:rbs.MirroringRequest.id)
  return id_;
}
inline void MirroringRequest::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:rbs.MirroringRequest.id)
}

// .rbs.MirroringReport report = 2;
inline bool MirroringRequest::has_report() const {
  return Mirroring_MSG_case() == kReport;
}
inline void MirroringRequest::set_has_report() {
  _oneof_case_[0] = kReport;
}
inline void MirroringRequest::clear_report() {
  if (has_report()) {
    delete Mirroring_MSG_.report_;
    clear_has_Mirroring_MSG();
  }
}
inline  const ::rbs::MirroringReport& MirroringRequest::report() const {
  // @@protoc_insertion_point(field_get:rbs.MirroringRequest.report)
  return has_report()
      ? *Mirroring_MSG_.report_
      : ::rbs::MirroringReport::default_instance();
}
inline ::rbs::MirroringReport* MirroringRequest::mutable_report() {
  if (!has_report()) {
    clear_Mirroring_MSG();
    set_has_report();
    Mirroring_MSG_.report_ = new ::rbs::MirroringReport;
  }
  // @@protoc_insertion_point(field_mutable:rbs.MirroringRequest.report)
  return Mirroring_MSG_.report_;
}
inline ::rbs::MirroringReport* MirroringRequest::release_report() {
  // @@protoc_insertion_point(field_release:rbs.MirroringRequest.report)
  if (has_report()) {
    clear_has_Mirroring_MSG();
    ::rbs::MirroringReport* temp = Mirroring_MSG_.report_;
    Mirroring_MSG_.report_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void MirroringRequest::set_allocated_report(::rbs::MirroringReport* report) {
  clear_Mirroring_MSG();
  if (report) {
    set_has_report();
    Mirroring_MSG_.report_ = report;
  }
  // @@protoc_insertion_point(field_set_allocated:rbs.MirroringRequest.report)
}

// string err = 99;
inline void MirroringRequest::clear_err() {
  err_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MirroringRequest::err() const {
  // @@protoc_insertion_point(field_get:rbs.MirroringRequest.err)
  return err_.GetNoArena();
}
inline void MirroringRequest::set_err(const ::std::string& value) {
  
  err_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:rbs.MirroringRequest.err)
}
#if LANG_CXX11
inline void MirroringRequest::set_err(::std::string&& value) {
  
  err_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:rbs.MirroringRequest.err)
}
#endif
inline void MirroringRequest::set_err(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  err_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:rbs.MirroringRequest.err)
}
inline void MirroringRequest::set_err(const char* value, size_t size) {
  
  err_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:rbs.MirroringRequest.err)
}
inline ::std::string* MirroringRequest::mutable_err() {
  
  // @@protoc_insertion_point(field_mutable:rbs.MirroringRequest.err)
  return err_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MirroringRequest::release_err() {
  // @@protoc_insertion_point(field_release:rbs.MirroringRequest.err)
  
  return err_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MirroringRequest::set_allocated_err(::std::string* err) {
  if (err != NULL) {
    
  } else {
    
  }
  err_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), err);
  // @@protoc_insertion_point(field_set_allocated:rbs.MirroringRequest.err)
}

inline bool MirroringRequest::has_Mirroring_MSG() const {
  return Mirroring_MSG_case() != MIRRORING_MSG_NOT_SET;
}
inline void MirroringRequest::clear_has_Mirroring_MSG() {
  _oneof_case_[0] = MIRRORING_MSG_NOT_SET;
}
inline MirroringRequest::MirroringMSGCase MirroringRequest::Mirroring_MSG_case() const {
  return MirroringRequest::MirroringMSGCase(_oneof_case_[0]);
}
// -------------------------------------------------------------------

// MirroringReplay

// int32 id = 1;
inline void MirroringReplay::clear_id() {
  id_ = 0;
}
inline ::google::protobuf::int32 MirroringReplay::id() const {
  // @@protoc_insertion_point(field_get:rbs.MirroringReplay.id)
  return id_;
}
inline void MirroringReplay::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:rbs.MirroringReplay.id)
}

// .rbs.MirrorSwitch switchon = 2;
inline bool MirroringReplay::has_switchon() const {
  return Mirroring_MSG_case() == kSwitchon;
}
inline void MirroringReplay::set_has_switchon() {
  _oneof_case_[0] = kSwitchon;
}
inline void MirroringReplay::clear_switchon() {
  if (has_switchon()) {
    delete Mirroring_MSG_.switchon_;
    clear_has_Mirroring_MSG();
  }
}
inline  const ::rbs::MirrorSwitch& MirroringReplay::switchon() const {
  // @@protoc_insertion_point(field_get:rbs.MirroringReplay.switchon)
  return has_switchon()
      ? *Mirroring_MSG_.switchon_
      : ::rbs::MirrorSwitch::default_instance();
}
inline ::rbs::MirrorSwitch* MirroringReplay::mutable_switchon() {
  if (!has_switchon()) {
    clear_Mirroring_MSG();
    set_has_switchon();
    Mirroring_MSG_.switchon_ = new ::rbs::MirrorSwitch;
  }
  // @@protoc_insertion_point(field_mutable:rbs.MirroringReplay.switchon)
  return Mirroring_MSG_.switchon_;
}
inline ::rbs::MirrorSwitch* MirroringReplay::release_switchon() {
  // @@protoc_insertion_point(field_release:rbs.MirroringReplay.switchon)
  if (has_switchon()) {
    clear_has_Mirroring_MSG();
    ::rbs::MirrorSwitch* temp = Mirroring_MSG_.switchon_;
    Mirroring_MSG_.switchon_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void MirroringReplay::set_allocated_switchon(::rbs::MirrorSwitch* switchon) {
  clear_Mirroring_MSG();
  if (switchon) {
    set_has_switchon();
    Mirroring_MSG_.switchon_ = switchon;
  }
  // @@protoc_insertion_point(field_set_allocated:rbs.MirroringReplay.switchon)
}

// string err = 99;
inline void MirroringReplay::clear_err() {
  err_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MirroringReplay::err() const {
  // @@protoc_insertion_point(field_get:rbs.MirroringReplay.err)
  return err_.GetNoArena();
}
inline void MirroringReplay::set_err(const ::std::string& value) {
  
  err_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:rbs.MirroringReplay.err)
}
#if LANG_CXX11
inline void MirroringReplay::set_err(::std::string&& value) {
  
  err_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:rbs.MirroringReplay.err)
}
#endif
inline void MirroringReplay::set_err(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  err_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:rbs.MirroringReplay.err)
}
inline void MirroringReplay::set_err(const char* value, size_t size) {
  
  err_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:rbs.MirroringReplay.err)
}
inline ::std::string* MirroringReplay::mutable_err() {
  
  // @@protoc_insertion_point(field_mutable:rbs.MirroringReplay.err)
  return err_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MirroringReplay::release_err() {
  // @@protoc_insertion_point(field_release:rbs.MirroringReplay.err)
  
  return err_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MirroringReplay::set_allocated_err(::std::string* err) {
  if (err != NULL) {
    
  } else {
    
  }
  err_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), err);
  // @@protoc_insertion_point(field_set_allocated:rbs.MirroringReplay.err)
}

inline bool MirroringReplay::has_Mirroring_MSG() const {
  return Mirroring_MSG_case() != MIRRORING_MSG_NOT_SET;
}
inline void MirroringReplay::clear_has_Mirroring_MSG() {
  _oneof_case_[0] = MIRRORING_MSG_NOT_SET;
}
inline MirroringReplay::MirroringMSGCase MirroringReplay::Mirroring_MSG_case() const {
  return MirroringReplay::MirroringMSGCase(_oneof_case_[0]);
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace rbs

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_mirroring_2eproto__INCLUDED
