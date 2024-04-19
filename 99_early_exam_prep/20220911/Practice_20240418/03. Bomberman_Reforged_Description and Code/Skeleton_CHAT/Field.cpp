#include "Field.h"

void Field::populateField(const FieldData &fieldData) {
  _fieldData = fieldData;
}

const FieldData &Field::getFieldData() const {
  return _fieldData;
}