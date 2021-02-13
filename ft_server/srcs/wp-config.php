<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'couscous' );

/** MySQL database password */
define( 'DB_PASSWORD', 'merguez22' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '!X- )z:3)9S0X8@*r*fw`79=#[pSl;</cKC#ImIkxzq6q[S`*6nyFI4KkRgV54.$' );
define( 'SECURE_AUTH_KEY',  'Afs|w;Wi#B8,zjzj+AUm)DOQ-G^czK=Txxqmu?bn$1FMIc>Zgd[s#8{ =(d=G+6m' );
define( 'LOGGED_IN_KEY',    '6/O l8GRa>S{4gkpdsq:/@z@@+AbwlBk}>j63|_QXl&NX;Gx],P`6a/4/X^c[7W|' );
define( 'NONCE_KEY',        'xxiKs5pstDAA5$S=EZj m8{lB@?h2,CJeL*G9]xja>-w|fkU7|KwRpvi|&f TV/`' );
define( 'AUTH_SALT',        '`?<=%!Ua/iu0fb%U=_+/M|ZgEWY[woCj:zxI[Rd#p]J#BhvT0hj~;uH,SMCpH:3;' );
define( 'SECURE_AUTH_SALT', '&Nok*_<pOYcxN7XRS:TGWoWV`|?t;pit{$q&+)Q]JKOb>{sy9s@7 8YL;}ZL1a&4' );
define( 'LOGGED_IN_SALT',   'Yym``EliV:#3u&M*y8#oUSyM8r*)vNikyE(#($k!MxG;Rf /3}oCk@;_0Urxvx!p' );
define( 'NONCE_SALT',       '.S(jE=G^<EzJ]D0e29[7M!BH>f;/8yp`%hX+s%28: qJeri*~k?vMEW}qS-qy7~}' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
