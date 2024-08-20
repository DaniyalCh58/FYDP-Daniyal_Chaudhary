% Specify the directory containing your data files
dataDir = 'D:\BCE\FYP\Dataset\IEEE\Session 1 Data\Session 1 All Participants\S1P43\';

% Specify the directory where you want to save the concatenated data
saveDir = 'D:\BCE\FYP\Dataset\IEEE\Session 1 Data\Session 1 All Participants All Gestures All Trials\';

% Create the save directory if it doesn't exist
if ~exist(saveDir, 'dir')
    mkdir(saveDir);
end

% Initialize variables to store concatenated data
concatenatedData = [];

% Loop through gesture files and concatenate data
for j = 1:4
    % Construct the file name for each gesture
    fileName = sprintf('session1_participant43_gesture%d_alltrials.mat', j);
   
    % Load the data from the MAT file
    data = load(fullfile(dataDir, fileName));

    % Access the numeric matrix within the structure
    reshapedData = data.reshapedData; % Replace 'YourNumericDataField' with the actual field name

    % Define the row range for this gesture
    startRow = (j - 1) * size(reshapedData, 1) + 1;
    endRow = j * size(reshapedData, 1);

    % Update the concatenatedData matrix
    concatenatedData(startRow:endRow, :) = reshapedData;
end

% Save the concatenated data to a new MAT file in the save directory
saveFileName = 'session1_participant43_allGesture_allTrials.mat';
save(fullfile(saveDir, saveFileName), 'concatenatedData');