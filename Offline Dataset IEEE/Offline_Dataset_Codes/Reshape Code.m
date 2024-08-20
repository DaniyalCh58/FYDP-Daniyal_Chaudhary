%This code loads the Single Participant File and Merge all it's 7 Trials in
%a single Matrix (Row and Column)

% Load the data from the MAT file
data = load('E:\BCE\FYP\Dataset\IEEE\Gesture Files\Gesture 1\session1_participant2.mat');

% Access the cell array containing the trials
trials = data.DATA; % Replace 'YourCellArrayName' with the actual variable name

% Concatenate all trials vertically
reshapedData = vertcat(trials{:});

% Now reshapedData is a (7*10240)x32 matrix, where rows represent concatenated trials