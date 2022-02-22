typedef struct dllobject dllobject;
typedef struct dlinkedlist dlinkedlist;

// Make the List, also creates the first object (With 0 as the contents)
dlinkedlist* dllCreate();

// Makes a slice of the original list (Not very well tested)
dlinkedlist* dllCreateSlice(dlinkedlist *list, int start, int end);

// Gets the pointer of an index
dllobject* dllGetAddr(dlinkedlist *list, int index);

// Pop (returns and removes) a value from an index
int dllPop(dlinkedlist *list, int index);

// Gets the value from an index
int dllGet(dlinkedlist *list, int index);

// Sets the value of an index
int dllSet(dlinkedlist *list, int index, int value);

// Add another value to the end of the list
int dllAppend(dlinkedlist *list, int value);