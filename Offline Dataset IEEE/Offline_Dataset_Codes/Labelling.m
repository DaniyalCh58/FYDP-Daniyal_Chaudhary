%labelling the Gestures NUMERICALLY 1,2,3,4

% Load the data from the MAT file
data = load('session1_participant1_allGestures_allTrials.mat');

% Access the numeric matrix within the structure
numericData = data.concatenatedData; % Replace 'YourNumericDataField' with the actual field name

% Determine the number of rows in the numeric data
numRows = size(numericData, 1);

% Initialize the label vector
labels = zeros(numRows, 1);

% Define row ranges for each gesture
gesture1Range = 1:71680;
gesture2Range = 71681:143360;
gesture3Range = 143361:215040;
gesture4Range = 215041:286720;

% Assign labels based on row ranges
labels(gesture1Range) = 1;  % Gesture 1 (IFE)
labels(gesture2Range) = 2;  % Gesture 2 (HO)
labels(gesture3Range) = 3;  % Gesture 3 (HC)
labels(gesture4Range) = 4;  % Gesture 4 (REST)

% Now 'labels' contains the assigned labels for each row in your data

% If you want to concatenate the labels with the numeric data
labeledData = [numericData, labels];

% Save the labeled data to a new MAT file
save('session1_participant1_labelled.mat', 'labeledData');
