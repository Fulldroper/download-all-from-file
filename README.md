The goal of this project was to create a CLI tool for downloading a list of files specified in a text file into a separate folder.

## Project Benefits
This project is useful for automating the downloading process for multiple files listed in a text file, saving time and effort.

## Project Description
This CLI tool reads a text file containing URLs of files to be downloaded and downloads each file into a specified folder.

## Repository Link and Installation Example
Repository: [Download All From File](https://github.com/Fulldroper/download-all-from-file)

### Installation
Clone the repository and compile the C++ code using a suitable compiler:

```bash
git clone https://github.com/Fulldroper/download-all-from-file
cd download-all-from-file
make
```

### Usage
Run the executable with the path to the text file containing URLs and the destination folder:

```bash
./download-all-from-file urls.txt /path/to/destination
```

## Project Workflow
1. **Read URLs from File**: The tool reads each line from the specified text file, treating each line as a URL.
    ```cpp
    std::ifstream file("urls.txt");
    std::string url;
    while (std::getline(file, url)) {
        // Process each URL
    }
    ```

2. **Download Files**: For each URL, the tool initiates a download process and saves the file to the specified directory.
    ```cpp
    // Example of a function to download a file
    void download_file(const std::string& url, const std::string& destination) {
        // Implementation of file download
    }
    ```

3. **Save to Directory**: The downloaded files are saved into the specified folder, maintaining the original file names.
    ```cpp
    std::string destination = "/path/to/destination";
    download_file(url, destination);
    ```

## Skills Acquired
- Proficiency in C++ programming
- Understanding of file I/O operations
- Familiarity with network programming and downloading files via URLs
- Command-line interface (CLI) tool development
