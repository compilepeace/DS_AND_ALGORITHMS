# hasattr(), getattr() and delattr()
# Instance attributes are those attributes which are not defined in the class but are individually
# alloted to the OBJECTS instead. Meaning that they are not part of the class (blueprint) but are 
# alloted separately after an instance (object) has been created.

# hasattr() returns True or False, depending on if the object has an attribute name "attribute_name"
# getattr() returns the attribute value, if attribute is not present it returns the default value
# delattr() deletes the attribute from the object

# hasattr(object, "attribute_name")
# getattr(object, "attribute_name", default_value)
# delattr(object, "attribute_name")

class Binary:
	pass

b1 = Binary()
b2 = Binary()

b1.name = "ls"
b1.id = 1

b2.id = 2

print(hasattr(b1, "name"))
print(hasattr(b2, "name"))

print(getattr(b1, "name"))
print(getattr(b2, "id"))

print( "Deleting attribute 'name' from b1... " )

delattr(b1, "name")
print(f"b1 has attributes : {b1.__dict__}")

print(getattr(b2, "name", "default_value : case of attribute not present"))

