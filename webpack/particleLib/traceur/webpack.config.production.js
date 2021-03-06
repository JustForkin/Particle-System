var webpack = require('webpack')
var path = require('path')

module.exports = {

  devtool: false,

  entry: {

    'ES6': [
      './ES6/src/ParticleSystem.js'
    ]
  },

  output: {
    path: path.join(__dirname, '../../../ES6/dist/traceur'),
    filename: 'ParticleSystem.js',
    libraryTarget: 'umd',
    library: 'Traceur'
  },

  plugins: [

    new webpack.NoErrorsPlugin(),
    new webpack.optimize.DedupePlugin(),
    new webpack.optimize.OccurenceOrderPlugin(),

    new webpack.optimize.MinChunkSizePlugin({
      minChunkSize: 51200
    }),

    new webpack.optimize.UglifyJsPlugin({
      output: {
        comments: false
      },
      compress: {
        warnings: false
      },
      minimize: true,
      mangle: true
    }),

    new webpack.DefinePlugin({
      'process.env.NODE_ENV': '"production"'
    })
  ],

  resolve: {
    extensions: ['', '.js', '.jsx', '.json'],
    root: [
      path.resolve('./ES6/src')
    ]
  },

  module: {

    loaders: [
      {
        test: /\.js$/,
        exclude: /node_modules/,
        loader: 'webpack-traceur?runtime&experimental'
      },
      {
        test: /\.json$/,
        loader: 'json-loader'
      },
      {
        test: /\.css$/,
        loader: 'style-loader!css-loader'
      },
      {
        test: /\.(jpe?g|png|gif|svg)$/i,
        loaders: [
          'file?hash=sha512&digest=hex&name=[hash].[ext]',
          'image-webpack?bypassOnDebug&optimizationLevel=7&interlaced=false'
        ]
      }
    ]
  }
}

