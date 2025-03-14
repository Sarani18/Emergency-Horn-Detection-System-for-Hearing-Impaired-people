<h2>Emergency Horn Detection System for Hearing Impaired people 🚓🚗</h2>
<h3>Project Description</h3>

<p>This repository contains a machine learning project for feature extraction and classification using multiple models, including 1D CNN, LSTM, and 2D CNN. The main focus of the project is to extract features from audio data, train various models, and evaluate their performance.</p>

<p>We used datasets from the internet for this project:</p>
<ul>
    <li><strong>Kaggle Siren Audio Dataset</strong></li>
    <li><strong>UrbanSound8K</strong></li>
</ul>
<p>The audio files used in this project are in WAV file format. Some files were converted to WAV format to ensure consistency across the dataset.</p>

<h3>Model Details</h3>
<p>The project involves the following models:</p>
<ul>
    <li><strong>1D Convolutional Neural Network (CNN)</strong>: Used for analyzing data sequences and capturing spatial hierarchies.</li>
    <li><strong>Long Short-Term Memory (LSTM)</strong>: Applied for sequential data modeling to capture temporal dependencies.</li>
    <li><strong>2D Convolutional Neural Network (CNN)</strong>: Designed with the following architecture:
        <ul>
            <li><strong>Convolutional Layers</strong>: Three <code>Conv2D</code> layers with padding set to 'same' to retain input dimensions.</li>
            <li><strong>Pooling Layers</strong>: <code>MaxPooling2D</code> layers with a pool size of (1, 1) to adjust dimensions as required.</li>
            <li><strong>Dropout</strong>: Dropout layers with a rate of 0.5 to prevent overfitting.</li>
            <li><strong>Fully Connected Layers</strong>: Dense layers to make final predictions, ending with a softmax activation for classification.</li>
        </ul>
    </li>
</ul>

<h3>How to Use</h3>
<ol>
    <li><strong>Install Dependencies</strong>: Ensure you have the required libraries installed. You can use the <code>requirements.txt</code> file (if provided) to install dependencies.</li>
    <li><strong>Run <code>main.py</code></strong>: Execute the script to perform feature extraction, train the model, and generate the model summary.</li>
    <li><strong>Load the Model</strong>: Use the <code>conv2d_model.h5</code> or <code>conv2d_model.keras</code> file to load the trained model for further predictions or evaluation.</li>
</ol>

<h3>Notes</h3>
<ul>
    <li>Ensure that your environment has the necessary resources (e.g., GPU) for training the model efficiently.</li>
    <li>Adjust the <code>input_shape</code> and other parameters in <code>main.py</code> according to your specific data and requirements.</li>
</ul>

