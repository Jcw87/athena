#pragma once

#include "YAMLDocReader.hpp"
#include "YAMLDocWriter.hpp"
#include "DNA.hpp"
#include "FileReader.hpp"
#include "FileWriter.hpp"

namespace athena::io {

template <class T>
inline const char* __GetDNAName(const T& dna, typename std::enable_if_t<athena::io::__IsDNAVRecord_v<T>>* = 0) {
  return dna.DNATypeV();
}

template <class T>
inline const char* __GetDNAName(const T& dna, typename std::enable_if_t<!athena::io::__IsDNAVRecord_v<T>>* = 0) {
  return dna.DNAType();
}

template <class T>
inline std::string ToYAMLString(const T& dna) {
  YAMLDocWriter docWriter(__GetDNAName(dna));

  std::string res;
  yaml_emitter_set_output(docWriter.getEmitter(), (yaml_write_handler_t*)YAMLStdStringWriter, &res);
  yaml_emitter_set_unicode(docWriter.getEmitter(), true);
  yaml_emitter_set_width(docWriter.getEmitter(), -1);

  dna.write(docWriter);
  if (!docWriter.finish(nullptr))
    return std::string();

  return res;
}

template <class T>
inline bool FromYAMLString(T& dna, std::string_view str) {
  YAMLStdStringViewReaderState reader(str);
  YAMLDocReader docReader;
  yaml_parser_set_input(docReader.getParser(), (yaml_read_handler_t*)YAMLStdStringReader, &reader);
  if (!docReader.parse(nullptr))
    return false;
  dna.read(docReader);
  return true;
}

template <class DNASubtype>
inline bool ValidateFromYAMLString(std::string_view str) {
  YAMLStdStringViewReaderState reader(str);
  YAMLDocReader docReader;
  yaml_parser_set_input(docReader.getParser(), (yaml_read_handler_t*)YAMLStdStringReader, &reader);
  bool retval = docReader.ValidateClassType(DNASubtype::DNAType());
  return retval;
}

template <class T>
inline bool ToYAMLStream(const T& dna, athena::io::IStreamWriter& fout) {
  YAMLDocWriter docWriter(__GetDNAName(dna));

  yaml_emitter_set_unicode(docWriter.getEmitter(), true);
  yaml_emitter_set_width(docWriter.getEmitter(), -1);

  dna.write(docWriter);
  return docWriter.finish(&fout);
}

template <class T>
inline bool ToYAMLStream(const T& dna, athena::io::IStreamWriter& fout,
                         void (T::*fn)(YAMLDocWriter& out) const) {
  YAMLDocWriter docWriter(__GetDNAName(dna));

  yaml_emitter_set_unicode(docWriter.getEmitter(), true);
  yaml_emitter_set_width(docWriter.getEmitter(), -1);

  (dna.*fn)(docWriter);
  return docWriter.finish(&fout);
}

template <class T>
inline bool FromYAMLStream(T& dna, athena::io::IStreamReader& fin) {
  YAMLDocReader docReader;
  if (!docReader.parse(&fin))
    return false;
  dna.read(docReader);
  return true;
}

template <class T>
inline bool FromYAMLStream(T& dna, athena::io::IStreamReader& fin, void (T::*fn)(YAMLDocReader& in)) {
  YAMLDocReader docReader;
  if (!docReader.parse(&fin))
    return false;
  (dna.*fn)(docReader);
  return true;
}

template <class T, typename NameT>
inline bool MergeToYAMLFile(const T& dna, const NameT& filename) {
  athena::io::FileReader r(filename);
  YAMLDocWriter docWriter(__GetDNAName(dna), r.isOpen() ? &r : nullptr);
  r.close();

  dna.write(docWriter);
  athena::io::FileWriter w(filename);
  if (!w.isOpen())
    return false;
  return docWriter.finish(&w);
}

template <class DNASubtype>
inline bool ValidateFromYAMLStream(athena::io::IStreamReader& fin) {
  YAMLDocReader reader;
  atUint64 pos = fin.position();
  yaml_parser_set_input(reader.getParser(), (yaml_read_handler_t*)YAMLAthenaReader, &fin);
  bool retval = reader.ValidateClassType(DNASubtype::DNAType());
  fin.seek(pos, athena::Begin);
  return retval;
}

} // namespace athena::io
