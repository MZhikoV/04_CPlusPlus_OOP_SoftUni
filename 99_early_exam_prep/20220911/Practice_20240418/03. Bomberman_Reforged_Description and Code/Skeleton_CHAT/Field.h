#ifndef FIELD_H_
#define FIELD_H_

#include "Defines.h"

class Field {
public:
  void populateField(const FieldData &fieldData);

  const FieldData &getFieldData() const;

private:
  FieldData _fieldData;
};

#endif /* FIELD_H_ */