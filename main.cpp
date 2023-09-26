/* In C++, please develop the following functionality: a dicom header reader that can read the header of a dicom file and return a dictionary of the header information. This should be able to read the header of any dicom file and return the information in a dictionary. */

#include <iostream>
#include <dcmtk/dcmdata/dctk.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <dicom-file>" << std::endl;
        return 1;
    }

    DcmFileFormat fileFormat;
    OFCondition status = fileFormat.loadFile(argv[1]);

    if (status.bad())
    {
        std::cerr << "Error: " << status.text() << std::endl;
        return 2;
    }

    DcmDataset *dataset = fileFormat.getDataset();

    // Example: Read the patient's name
    OFString patientName;
    if (dataset->findAndGetOFString(DCM_PatientName, patientName).good())
    {
        std::cout << "Patient's Name: " << patientName << std::endl;
    }
    else
    {
        std::cerr << "Error: Cannot access Patient's Name!" << std::endl;
    }

    // You can similarly read other tags...

    return 0;
}
