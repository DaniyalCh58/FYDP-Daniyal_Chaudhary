import scipy.io

# Path to your MATLAB file
mat_file_path = "E:/BCE/FYP/Dataset/IEEE/Session 1/session1_participant1.mat"

# Load the .mat file
mat_data = scipy.io.loadmat(mat_file_path)

# Print the keys (variable names) in the .mat file
print(mat_data.keys())