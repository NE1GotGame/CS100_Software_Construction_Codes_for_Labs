#ifndef __SELECT_HPP__
#define __SELECT_HPP__

#include <cstring>

class Select
{
public:
    virtual ~Select() = default;

    // Return true if the specified row should be selected.
    virtual bool select(const Spreadsheet* sheet, int row) const = 0;
};

// A common type of criterion for selection is to perform a comparison based on
// the contents of one column.  This class contains contains the logic needed
// for dealing with columns. Note that this class is also an abstract base
// class, derived from Select.  It introduces a new select function (taking just
// a string) and implements the original interface in terms of this.  Derived
// classes need only implement the new select function.  You may choose to
// derive from Select or Select_Column at your convenience.
class Select_Column: public Select
{
protected:
    int column;
public:
    Select_Column(const Spreadsheet* sheet, const std::string& name)
    {
        column = sheet->get_column_by_name(name);
    }

    virtual bool select(const Spreadsheet* sheet, int row) const
    {
        return select(sheet->cell_data(row, column));
    }

    // Derived classes can instead implement this simpler interface.
    virtual bool select(const std::string& s) const = 0;
};


class Select_Contains: public Select_Column
{
    private:
	Spreadsheet* sheet1;
	std::string column;
	std::string key;

    public:
	Select_Contains(const Spreadsheet* sheet, const std::string& category, const std::string& word)
    {
	sheet1 = sheet;
	column = category;
	key = word;
	Select_Column(sheet, column);
    }
	bool select(const Spreadsheet* sheet, int row) const
	{
	    if(sheet1->cell_data(row,column).find(key) != this->npos)
	    {
		return true;	    
	    }
	    return false;
	}
};








#endif //__SELECT_HPP__
