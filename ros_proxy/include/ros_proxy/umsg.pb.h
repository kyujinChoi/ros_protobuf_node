// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: umsg.proto

#ifndef PROTOBUF_INCLUDED_umsg_2eproto
#define PROTOBUF_INCLUDED_umsg_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_umsg_2eproto 

namespace protobuf_umsg_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[4];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_umsg_2eproto
namespace vcf {
class Initial_msg;
class Initial_msgDefaultTypeInternal;
extern Initial_msgDefaultTypeInternal _Initial_msg_default_instance_;
class Initial_msg_Cmd;
class Initial_msg_CmdDefaultTypeInternal;
extern Initial_msg_CmdDefaultTypeInternal _Initial_msg_Cmd_default_instance_;
class Initial_msg_Prm;
class Initial_msg_PrmDefaultTypeInternal;
extern Initial_msg_PrmDefaultTypeInternal _Initial_msg_Prm_default_instance_;
class Operational_msg;
class Operational_msgDefaultTypeInternal;
extern Operational_msgDefaultTypeInternal _Operational_msg_default_instance_;
}  // namespace vcf
namespace google {
namespace protobuf {
template<> ::vcf::Initial_msg* Arena::CreateMaybeMessage<::vcf::Initial_msg>(Arena*);
template<> ::vcf::Initial_msg_Cmd* Arena::CreateMaybeMessage<::vcf::Initial_msg_Cmd>(Arena*);
template<> ::vcf::Initial_msg_Prm* Arena::CreateMaybeMessage<::vcf::Initial_msg_Prm>(Arena*);
template<> ::vcf::Operational_msg* Arena::CreateMaybeMessage<::vcf::Operational_msg>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace vcf {

// ===================================================================

class Initial_msg_Cmd : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:vcf.Initial_msg.Cmd) */ {
 public:
  Initial_msg_Cmd();
  virtual ~Initial_msg_Cmd();

  Initial_msg_Cmd(const Initial_msg_Cmd& from);

  inline Initial_msg_Cmd& operator=(const Initial_msg_Cmd& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Initial_msg_Cmd(Initial_msg_Cmd&& from) noexcept
    : Initial_msg_Cmd() {
    *this = ::std::move(from);
  }

  inline Initial_msg_Cmd& operator=(Initial_msg_Cmd&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Initial_msg_Cmd& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Initial_msg_Cmd* internal_default_instance() {
    return reinterpret_cast<const Initial_msg_Cmd*>(
               &_Initial_msg_Cmd_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Initial_msg_Cmd* other);
  friend void swap(Initial_msg_Cmd& a, Initial_msg_Cmd& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Initial_msg_Cmd* New() const final {
    return CreateMaybeMessage<Initial_msg_Cmd>(NULL);
  }

  Initial_msg_Cmd* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Initial_msg_Cmd>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Initial_msg_Cmd& from);
  void MergeFrom(const Initial_msg_Cmd& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Initial_msg_Cmd* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string _name = 2;
  void clear__name();
  static const int kNameFieldNumber = 2;
  const ::std::string& _name() const;
  void set__name(const ::std::string& value);
  #if LANG_CXX11
  void set__name(::std::string&& value);
  #endif
  void set__name(const char* value);
  void set__name(const char* value, size_t size);
  ::std::string* mutable__name();
  ::std::string* release__name();
  void set_allocated__name(::std::string* _name);

  // uint32 _from = 1;
  void clear__from();
  static const int kFromFieldNumber = 1;
  ::google::protobuf::uint32 _from() const;
  void set__from(::google::protobuf::uint32 value);

  // int32 _value = 4;
  void clear__value();
  static const int kValueFieldNumber = 4;
  ::google::protobuf::int32 _value() const;
  void set__value(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:vcf.Initial_msg.Cmd)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr _name_;
  ::google::protobuf::uint32 _from_;
  ::google::protobuf::int32 _value_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_umsg_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Initial_msg_Prm : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:vcf.Initial_msg.Prm) */ {
 public:
  Initial_msg_Prm();
  virtual ~Initial_msg_Prm();

  Initial_msg_Prm(const Initial_msg_Prm& from);

  inline Initial_msg_Prm& operator=(const Initial_msg_Prm& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Initial_msg_Prm(Initial_msg_Prm&& from) noexcept
    : Initial_msg_Prm() {
    *this = ::std::move(from);
  }

  inline Initial_msg_Prm& operator=(Initial_msg_Prm&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Initial_msg_Prm& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Initial_msg_Prm* internal_default_instance() {
    return reinterpret_cast<const Initial_msg_Prm*>(
               &_Initial_msg_Prm_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Initial_msg_Prm* other);
  friend void swap(Initial_msg_Prm& a, Initial_msg_Prm& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Initial_msg_Prm* New() const final {
    return CreateMaybeMessage<Initial_msg_Prm>(NULL);
  }

  Initial_msg_Prm* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Initial_msg_Prm>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Initial_msg_Prm& from);
  void MergeFrom(const Initial_msg_Prm& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Initial_msg_Prm* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // uint32 _vartype = 1;
  void clear__vartype();
  static const int kVartypeFieldNumber = 1;
  ::google::protobuf::uint32 _vartype() const;
  void set__vartype(::google::protobuf::uint32 value);

  // int32 _min = 2;
  void clear__min();
  static const int kMinFieldNumber = 2;
  ::google::protobuf::int32 _min() const;
  void set__min(::google::protobuf::int32 value);

  // int32 _max = 3;
  void clear__max();
  static const int kMaxFieldNumber = 3;
  ::google::protobuf::int32 _max() const;
  void set__max(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:vcf.Initial_msg.Prm)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _vartype_;
  ::google::protobuf::int32 _min_;
  ::google::protobuf::int32 _max_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_umsg_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Initial_msg : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:vcf.Initial_msg) */ {
 public:
  Initial_msg();
  virtual ~Initial_msg();

  Initial_msg(const Initial_msg& from);

  inline Initial_msg& operator=(const Initial_msg& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Initial_msg(Initial_msg&& from) noexcept
    : Initial_msg() {
    *this = ::std::move(from);
  }

  inline Initial_msg& operator=(Initial_msg&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Initial_msg& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Initial_msg* internal_default_instance() {
    return reinterpret_cast<const Initial_msg*>(
               &_Initial_msg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(Initial_msg* other);
  friend void swap(Initial_msg& a, Initial_msg& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Initial_msg* New() const final {
    return CreateMaybeMessage<Initial_msg>(NULL);
  }

  Initial_msg* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Initial_msg>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Initial_msg& from);
  void MergeFrom(const Initial_msg& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Initial_msg* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef Initial_msg_Cmd Cmd;
  typedef Initial_msg_Prm Prm;

  // accessors -------------------------------------------------------

  // repeated .vcf.Initial_msg.Cmd cmd = 5;
  int cmd_size() const;
  void clear_cmd();
  static const int kCmdFieldNumber = 5;
  ::vcf::Initial_msg_Cmd* mutable_cmd(int index);
  ::google::protobuf::RepeatedPtrField< ::vcf::Initial_msg_Cmd >*
      mutable_cmd();
  const ::vcf::Initial_msg_Cmd& cmd(int index) const;
  ::vcf::Initial_msg_Cmd* add_cmd();
  const ::google::protobuf::RepeatedPtrField< ::vcf::Initial_msg_Cmd >&
      cmd() const;

  // repeated .vcf.Initial_msg.Prm prm = 6;
  int prm_size() const;
  void clear_prm();
  static const int kPrmFieldNumber = 6;
  ::vcf::Initial_msg_Prm* mutable_prm(int index);
  ::google::protobuf::RepeatedPtrField< ::vcf::Initial_msg_Prm >*
      mutable_prm();
  const ::vcf::Initial_msg_Prm& prm(int index) const;
  ::vcf::Initial_msg_Prm* add_prm();
  const ::google::protobuf::RepeatedPtrField< ::vcf::Initial_msg_Prm >&
      prm() const;

  // string _msg = 4;
  void clear__msg();
  static const int kMsgFieldNumber = 4;
  const ::std::string& _msg() const;
  void set__msg(const ::std::string& value);
  #if LANG_CXX11
  void set__msg(::std::string&& value);
  #endif
  void set__msg(const char* value);
  void set__msg(const char* value, size_t size);
  ::std::string* mutable__msg();
  ::std::string* release__msg();
  void set_allocated__msg(::std::string* _msg);

  // uint32 _seqNo = 1;
  void clear__seqno();
  static const int kSeqNoFieldNumber = 1;
  ::google::protobuf::uint32 _seqno() const;
  void set__seqno(::google::protobuf::uint32 value);

  // uint32 _version = 2;
  void clear__version();
  static const int kVersionFieldNumber = 2;
  ::google::protobuf::uint32 _version() const;
  void set__version(::google::protobuf::uint32 value);

  // int32 _result = 3;
  void clear__result();
  static const int kResultFieldNumber = 3;
  ::google::protobuf::int32 _result() const;
  void set__result(::google::protobuf::int32 value);

  // uint32 _cycle = 7;
  void clear__cycle();
  static const int kCycleFieldNumber = 7;
  ::google::protobuf::uint32 _cycle() const;
  void set__cycle(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:vcf.Initial_msg)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::vcf::Initial_msg_Cmd > cmd_;
  ::google::protobuf::RepeatedPtrField< ::vcf::Initial_msg_Prm > prm_;
  ::google::protobuf::internal::ArenaStringPtr _msg_;
  ::google::protobuf::uint32 _seqno_;
  ::google::protobuf::uint32 _version_;
  ::google::protobuf::int32 _result_;
  ::google::protobuf::uint32 _cycle_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_umsg_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Operational_msg : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:vcf.Operational_msg) */ {
 public:
  Operational_msg();
  virtual ~Operational_msg();

  Operational_msg(const Operational_msg& from);

  inline Operational_msg& operator=(const Operational_msg& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Operational_msg(Operational_msg&& from) noexcept
    : Operational_msg() {
    *this = ::std::move(from);
  }

  inline Operational_msg& operator=(Operational_msg&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Operational_msg& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Operational_msg* internal_default_instance() {
    return reinterpret_cast<const Operational_msg*>(
               &_Operational_msg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(Operational_msg* other);
  friend void swap(Operational_msg& a, Operational_msg& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Operational_msg* New() const final {
    return CreateMaybeMessage<Operational_msg>(NULL);
  }

  Operational_msg* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Operational_msg>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Operational_msg& from);
  void MergeFrom(const Operational_msg& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Operational_msg* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string _name = 4;
  void clear__name();
  static const int kNameFieldNumber = 4;
  const ::std::string& _name() const;
  void set__name(const ::std::string& value);
  #if LANG_CXX11
  void set__name(::std::string&& value);
  #endif
  void set__name(const char* value);
  void set__name(const char* value, size_t size);
  ::std::string* mutable__name();
  ::std::string* release__name();
  void set_allocated__name(::std::string* _name);

  // string _msg = 7;
  void clear__msg();
  static const int kMsgFieldNumber = 7;
  const ::std::string& _msg() const;
  void set__msg(const ::std::string& value);
  #if LANG_CXX11
  void set__msg(::std::string&& value);
  #endif
  void set__msg(const char* value);
  void set__msg(const char* value, size_t size);
  ::std::string* mutable__msg();
  ::std::string* release__msg();
  void set_allocated__msg(::std::string* _msg);

  // uint32 _seqNo = 1;
  void clear__seqno();
  static const int kSeqNoFieldNumber = 1;
  ::google::protobuf::uint32 _seqno() const;
  void set__seqno(::google::protobuf::uint32 value);

  // uint32 _from = 2;
  void clear__from();
  static const int kFromFieldNumber = 2;
  ::google::protobuf::uint32 _from() const;
  void set__from(::google::protobuf::uint32 value);

  // uint32 _to = 3;
  void clear__to();
  static const int kToFieldNumber = 3;
  ::google::protobuf::uint32 _to() const;
  void set__to(::google::protobuf::uint32 value);

  // int32 _value = 5;
  void clear__value();
  static const int kValueFieldNumber = 5;
  ::google::protobuf::int32 _value() const;
  void set__value(::google::protobuf::int32 value);

  // int32 _result = 6;
  void clear__result();
  static const int kResultFieldNumber = 6;
  ::google::protobuf::int32 _result() const;
  void set__result(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:vcf.Operational_msg)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr _name_;
  ::google::protobuf::internal::ArenaStringPtr _msg_;
  ::google::protobuf::uint32 _seqno_;
  ::google::protobuf::uint32 _from_;
  ::google::protobuf::uint32 _to_;
  ::google::protobuf::int32 _value_;
  ::google::protobuf::int32 _result_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_umsg_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Initial_msg_Cmd

// uint32 _from = 1;
inline void Initial_msg_Cmd::clear__from() {
  _from_ = 0u;
}
inline ::google::protobuf::uint32 Initial_msg_Cmd::_from() const {
  // @@protoc_insertion_point(field_get:vcf.Initial_msg.Cmd._from)
  return _from_;
}
inline void Initial_msg_Cmd::set__from(::google::protobuf::uint32 value) {
  
  _from_ = value;
  // @@protoc_insertion_point(field_set:vcf.Initial_msg.Cmd._from)
}

// string _name = 2;
inline void Initial_msg_Cmd::clear__name() {
  _name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Initial_msg_Cmd::_name() const {
  // @@protoc_insertion_point(field_get:vcf.Initial_msg.Cmd._name)
  return _name_.GetNoArena();
}
inline void Initial_msg_Cmd::set__name(const ::std::string& value) {
  
  _name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:vcf.Initial_msg.Cmd._name)
}
#if LANG_CXX11
inline void Initial_msg_Cmd::set__name(::std::string&& value) {
  
  _name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:vcf.Initial_msg.Cmd._name)
}
#endif
inline void Initial_msg_Cmd::set__name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  _name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:vcf.Initial_msg.Cmd._name)
}
inline void Initial_msg_Cmd::set__name(const char* value, size_t size) {
  
  _name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:vcf.Initial_msg.Cmd._name)
}
inline ::std::string* Initial_msg_Cmd::mutable__name() {
  
  // @@protoc_insertion_point(field_mutable:vcf.Initial_msg.Cmd._name)
  return _name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Initial_msg_Cmd::release__name() {
  // @@protoc_insertion_point(field_release:vcf.Initial_msg.Cmd._name)
  
  return _name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Initial_msg_Cmd::set_allocated__name(::std::string* _name) {
  if (_name != NULL) {
    
  } else {
    
  }
  _name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), _name);
  // @@protoc_insertion_point(field_set_allocated:vcf.Initial_msg.Cmd._name)
}

// int32 _value = 4;
inline void Initial_msg_Cmd::clear__value() {
  _value_ = 0;
}
inline ::google::protobuf::int32 Initial_msg_Cmd::_value() const {
  // @@protoc_insertion_point(field_get:vcf.Initial_msg.Cmd._value)
  return _value_;
}
inline void Initial_msg_Cmd::set__value(::google::protobuf::int32 value) {
  
  _value_ = value;
  // @@protoc_insertion_point(field_set:vcf.Initial_msg.Cmd._value)
}

// -------------------------------------------------------------------

// Initial_msg_Prm

// uint32 _vartype = 1;
inline void Initial_msg_Prm::clear__vartype() {
  _vartype_ = 0u;
}
inline ::google::protobuf::uint32 Initial_msg_Prm::_vartype() const {
  // @@protoc_insertion_point(field_get:vcf.Initial_msg.Prm._vartype)
  return _vartype_;
}
inline void Initial_msg_Prm::set__vartype(::google::protobuf::uint32 value) {
  
  _vartype_ = value;
  // @@protoc_insertion_point(field_set:vcf.Initial_msg.Prm._vartype)
}

// int32 _min = 2;
inline void Initial_msg_Prm::clear__min() {
  _min_ = 0;
}
inline ::google::protobuf::int32 Initial_msg_Prm::_min() const {
  // @@protoc_insertion_point(field_get:vcf.Initial_msg.Prm._min)
  return _min_;
}
inline void Initial_msg_Prm::set__min(::google::protobuf::int32 value) {
  
  _min_ = value;
  // @@protoc_insertion_point(field_set:vcf.Initial_msg.Prm._min)
}

// int32 _max = 3;
inline void Initial_msg_Prm::clear__max() {
  _max_ = 0;
}
inline ::google::protobuf::int32 Initial_msg_Prm::_max() const {
  // @@protoc_insertion_point(field_get:vcf.Initial_msg.Prm._max)
  return _max_;
}
inline void Initial_msg_Prm::set__max(::google::protobuf::int32 value) {
  
  _max_ = value;
  // @@protoc_insertion_point(field_set:vcf.Initial_msg.Prm._max)
}

// -------------------------------------------------------------------

// Initial_msg

// uint32 _seqNo = 1;
inline void Initial_msg::clear__seqno() {
  _seqno_ = 0u;
}
inline ::google::protobuf::uint32 Initial_msg::_seqno() const {
  // @@protoc_insertion_point(field_get:vcf.Initial_msg._seqNo)
  return _seqno_;
}
inline void Initial_msg::set__seqno(::google::protobuf::uint32 value) {
  
  _seqno_ = value;
  // @@protoc_insertion_point(field_set:vcf.Initial_msg._seqNo)
}

// uint32 _version = 2;
inline void Initial_msg::clear__version() {
  _version_ = 0u;
}
inline ::google::protobuf::uint32 Initial_msg::_version() const {
  // @@protoc_insertion_point(field_get:vcf.Initial_msg._version)
  return _version_;
}
inline void Initial_msg::set__version(::google::protobuf::uint32 value) {
  
  _version_ = value;
  // @@protoc_insertion_point(field_set:vcf.Initial_msg._version)
}

// int32 _result = 3;
inline void Initial_msg::clear__result() {
  _result_ = 0;
}
inline ::google::protobuf::int32 Initial_msg::_result() const {
  // @@protoc_insertion_point(field_get:vcf.Initial_msg._result)
  return _result_;
}
inline void Initial_msg::set__result(::google::protobuf::int32 value) {
  
  _result_ = value;
  // @@protoc_insertion_point(field_set:vcf.Initial_msg._result)
}

// string _msg = 4;
inline void Initial_msg::clear__msg() {
  _msg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Initial_msg::_msg() const {
  // @@protoc_insertion_point(field_get:vcf.Initial_msg._msg)
  return _msg_.GetNoArena();
}
inline void Initial_msg::set__msg(const ::std::string& value) {
  
  _msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:vcf.Initial_msg._msg)
}
#if LANG_CXX11
inline void Initial_msg::set__msg(::std::string&& value) {
  
  _msg_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:vcf.Initial_msg._msg)
}
#endif
inline void Initial_msg::set__msg(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  _msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:vcf.Initial_msg._msg)
}
inline void Initial_msg::set__msg(const char* value, size_t size) {
  
  _msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:vcf.Initial_msg._msg)
}
inline ::std::string* Initial_msg::mutable__msg() {
  
  // @@protoc_insertion_point(field_mutable:vcf.Initial_msg._msg)
  return _msg_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Initial_msg::release__msg() {
  // @@protoc_insertion_point(field_release:vcf.Initial_msg._msg)
  
  return _msg_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Initial_msg::set_allocated__msg(::std::string* _msg) {
  if (_msg != NULL) {
    
  } else {
    
  }
  _msg_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), _msg);
  // @@protoc_insertion_point(field_set_allocated:vcf.Initial_msg._msg)
}

// repeated .vcf.Initial_msg.Cmd cmd = 5;
inline int Initial_msg::cmd_size() const {
  return cmd_.size();
}
inline void Initial_msg::clear_cmd() {
  cmd_.Clear();
}
inline ::vcf::Initial_msg_Cmd* Initial_msg::mutable_cmd(int index) {
  // @@protoc_insertion_point(field_mutable:vcf.Initial_msg.cmd)
  return cmd_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::vcf::Initial_msg_Cmd >*
Initial_msg::mutable_cmd() {
  // @@protoc_insertion_point(field_mutable_list:vcf.Initial_msg.cmd)
  return &cmd_;
}
inline const ::vcf::Initial_msg_Cmd& Initial_msg::cmd(int index) const {
  // @@protoc_insertion_point(field_get:vcf.Initial_msg.cmd)
  return cmd_.Get(index);
}
inline ::vcf::Initial_msg_Cmd* Initial_msg::add_cmd() {
  // @@protoc_insertion_point(field_add:vcf.Initial_msg.cmd)
  return cmd_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::vcf::Initial_msg_Cmd >&
Initial_msg::cmd() const {
  // @@protoc_insertion_point(field_list:vcf.Initial_msg.cmd)
  return cmd_;
}

// repeated .vcf.Initial_msg.Prm prm = 6;
inline int Initial_msg::prm_size() const {
  return prm_.size();
}
inline void Initial_msg::clear_prm() {
  prm_.Clear();
}
inline ::vcf::Initial_msg_Prm* Initial_msg::mutable_prm(int index) {
  // @@protoc_insertion_point(field_mutable:vcf.Initial_msg.prm)
  return prm_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::vcf::Initial_msg_Prm >*
Initial_msg::mutable_prm() {
  // @@protoc_insertion_point(field_mutable_list:vcf.Initial_msg.prm)
  return &prm_;
}
inline const ::vcf::Initial_msg_Prm& Initial_msg::prm(int index) const {
  // @@protoc_insertion_point(field_get:vcf.Initial_msg.prm)
  return prm_.Get(index);
}
inline ::vcf::Initial_msg_Prm* Initial_msg::add_prm() {
  // @@protoc_insertion_point(field_add:vcf.Initial_msg.prm)
  return prm_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::vcf::Initial_msg_Prm >&
Initial_msg::prm() const {
  // @@protoc_insertion_point(field_list:vcf.Initial_msg.prm)
  return prm_;
}

// uint32 _cycle = 7;
inline void Initial_msg::clear__cycle() {
  _cycle_ = 0u;
}
inline ::google::protobuf::uint32 Initial_msg::_cycle() const {
  // @@protoc_insertion_point(field_get:vcf.Initial_msg._cycle)
  return _cycle_;
}
inline void Initial_msg::set__cycle(::google::protobuf::uint32 value) {
  
  _cycle_ = value;
  // @@protoc_insertion_point(field_set:vcf.Initial_msg._cycle)
}

// -------------------------------------------------------------------

// Operational_msg

// uint32 _seqNo = 1;
inline void Operational_msg::clear__seqno() {
  _seqno_ = 0u;
}
inline ::google::protobuf::uint32 Operational_msg::_seqno() const {
  // @@protoc_insertion_point(field_get:vcf.Operational_msg._seqNo)
  return _seqno_;
}
inline void Operational_msg::set__seqno(::google::protobuf::uint32 value) {
  
  _seqno_ = value;
  // @@protoc_insertion_point(field_set:vcf.Operational_msg._seqNo)
}

// uint32 _from = 2;
inline void Operational_msg::clear__from() {
  _from_ = 0u;
}
inline ::google::protobuf::uint32 Operational_msg::_from() const {
  // @@protoc_insertion_point(field_get:vcf.Operational_msg._from)
  return _from_;
}
inline void Operational_msg::set__from(::google::protobuf::uint32 value) {
  
  _from_ = value;
  // @@protoc_insertion_point(field_set:vcf.Operational_msg._from)
}

// uint32 _to = 3;
inline void Operational_msg::clear__to() {
  _to_ = 0u;
}
inline ::google::protobuf::uint32 Operational_msg::_to() const {
  // @@protoc_insertion_point(field_get:vcf.Operational_msg._to)
  return _to_;
}
inline void Operational_msg::set__to(::google::protobuf::uint32 value) {
  
  _to_ = value;
  // @@protoc_insertion_point(field_set:vcf.Operational_msg._to)
}

// string _name = 4;
inline void Operational_msg::clear__name() {
  _name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Operational_msg::_name() const {
  // @@protoc_insertion_point(field_get:vcf.Operational_msg._name)
  return _name_.GetNoArena();
}
inline void Operational_msg::set__name(const ::std::string& value) {
  
  _name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:vcf.Operational_msg._name)
}
#if LANG_CXX11
inline void Operational_msg::set__name(::std::string&& value) {
  
  _name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:vcf.Operational_msg._name)
}
#endif
inline void Operational_msg::set__name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  _name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:vcf.Operational_msg._name)
}
inline void Operational_msg::set__name(const char* value, size_t size) {
  
  _name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:vcf.Operational_msg._name)
}
inline ::std::string* Operational_msg::mutable__name() {
  
  // @@protoc_insertion_point(field_mutable:vcf.Operational_msg._name)
  return _name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Operational_msg::release__name() {
  // @@protoc_insertion_point(field_release:vcf.Operational_msg._name)
  
  return _name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Operational_msg::set_allocated__name(::std::string* _name) {
  if (_name != NULL) {
    
  } else {
    
  }
  _name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), _name);
  // @@protoc_insertion_point(field_set_allocated:vcf.Operational_msg._name)
}

// int32 _value = 5;
inline void Operational_msg::clear__value() {
  _value_ = 0;
}
inline ::google::protobuf::int32 Operational_msg::_value() const {
  // @@protoc_insertion_point(field_get:vcf.Operational_msg._value)
  return _value_;
}
inline void Operational_msg::set__value(::google::protobuf::int32 value) {
  
  _value_ = value;
  // @@protoc_insertion_point(field_set:vcf.Operational_msg._value)
}

// int32 _result = 6;
inline void Operational_msg::clear__result() {
  _result_ = 0;
}
inline ::google::protobuf::int32 Operational_msg::_result() const {
  // @@protoc_insertion_point(field_get:vcf.Operational_msg._result)
  return _result_;
}
inline void Operational_msg::set__result(::google::protobuf::int32 value) {
  
  _result_ = value;
  // @@protoc_insertion_point(field_set:vcf.Operational_msg._result)
}

// string _msg = 7;
inline void Operational_msg::clear__msg() {
  _msg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Operational_msg::_msg() const {
  // @@protoc_insertion_point(field_get:vcf.Operational_msg._msg)
  return _msg_.GetNoArena();
}
inline void Operational_msg::set__msg(const ::std::string& value) {
  
  _msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:vcf.Operational_msg._msg)
}
#if LANG_CXX11
inline void Operational_msg::set__msg(::std::string&& value) {
  
  _msg_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:vcf.Operational_msg._msg)
}
#endif
inline void Operational_msg::set__msg(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  _msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:vcf.Operational_msg._msg)
}
inline void Operational_msg::set__msg(const char* value, size_t size) {
  
  _msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:vcf.Operational_msg._msg)
}
inline ::std::string* Operational_msg::mutable__msg() {
  
  // @@protoc_insertion_point(field_mutable:vcf.Operational_msg._msg)
  return _msg_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Operational_msg::release__msg() {
  // @@protoc_insertion_point(field_release:vcf.Operational_msg._msg)
  
  return _msg_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Operational_msg::set_allocated__msg(::std::string* _msg) {
  if (_msg != NULL) {
    
  } else {
    
  }
  _msg_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), _msg);
  // @@protoc_insertion_point(field_set_allocated:vcf.Operational_msg._msg)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace vcf

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_umsg_2eproto