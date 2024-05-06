#ifndef _LIST_INTERFACE
#define _LIST_INTERFACE

class ListInterface {
public:
	/* Determines whether this list is empty
	@return true if the list is empty; otherwise returns false
	*/
	virtual bool isEmpty() const = 0;

	/* Gets the current number of entries in the list
	@return  the integer number of entries currently in the list
	*/
	virtual int getLength() const = 0;

	/* Inserts an entry into this list at a given position
	@pre None
	@post if 1 <= position <= getLength() + 1 and the insertion is successful, new Entry is at the given position in the list, other entries are renumbered accordingly, and the returned value is true.
	@param newPosition - The list position at which to insert newEntry
	@param newEntry - The entry to insert into the list
	@return - true if insertion is successful, or false if not
	*/
	virtual bool insert(int newPosition, const int& newEntry) = 0;

	/* removes the entry at a given position from this list 
	@pre None
	@post - if 1 <= position <= getLength() + 1 and the removal is successful, the entry at the given position in the list is removed, other items are renumbered accordingly, and the returned value is true.
	@param position - the list position of the entry to remove
	@return - true if removal is successful, or false if not
	*/
	virtual bool remove(int position) = 0;

	/* removes all entries from this list
	@post list contains no entries and the count of items is 0.
	*/
	virtual void clear() = 0;

	/* gets the entry at the given position in this list
	@pre 1 <= position <= getLength() + 1
	@post The desired entry has been returned
	@param position - The list position of the desired entry
	@return The entry at teh given position
	*/
	virtual int getEntry(int position) const = 0;

	/* Replaces the entry at the given position in this list
	@pre 1 <= position <= getLength() + 1
	@post The entry at the given position is newEntry
	@param position - the list position of the entry to replace
	@param newEntry - The replacement entry
	*/
	virtual void setEntry(int position, const int& newEntry) = 0;
};

#endif