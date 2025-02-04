 % Specify the directory containing your data files
dataDir = 'E:\BCE\FYP\Dataset\IEEE\Gesture Files\Gesture 4';

% Specify the directory where you want to save the reshaped data
saveDir = 'E:\BCE\FYP\Dataset\IEEE\Gesture Files\Session 1 Gesture 4 All Trials';

% Create the save directory if it doesn't exist
if ~exist(saveDir, 'dir')
    mkdir(saveDir);
end

% Loop through participant files and reshape data
for j = 1:43
    % Construct the file name for each participant
    fileName = sprintf('session1_participant%d.mat', j);
    
    % Load the data from the MAT file
    data = load(fullfile(dataDir, fileName));

    % Access the cell array containing the trials
    trials = data.DATA; % Replace 'YourCellArrayName' with the actual variable name

    % Concatenate all trials vertically
    reshapedData = vertcat(trials{:});

    % Save the reshaped data to a new MAT file in the save directory
    saveFileName = sprintf('session1_participant%d_gesture4_alltrials.mat', j);
    save(fullfile(saveDir, saveFileName), 'reshapedData');
end
